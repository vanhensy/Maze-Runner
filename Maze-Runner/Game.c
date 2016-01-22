#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void print_steps(int step_left);
void run_game();
void sleep(unsigned int mseconds);
void main() {
	analysis_maze();
	hidecursor();
	gotoxy(0, 6);
	add_color(true, 1);
	print_intro();
	add_color(false, NULL);
	char mode = _getch();
	if ( mode == '1') {
		system("cls");
		run_game();
	}
	else if (mode == '2') {
		system("cls");
		AutoMove();
	}
	else {
		printf("Please choose the mode !");
	}
	getch();
}

void print_steps(int step_left) {
	gotoxy(10, 1);
	printf("STEPS: %i", 100 - step_left);
}

void run_game()  {
	int step_counter = 0;
	gotoxy(0, 3);
	print_maze();
	add_color(true, 1);
	gotoxy(12, 4);
	printf("%c", 219);
	add_color(false, NULL);
	print_position(12, 4);
	for (step_counter; step_counter < 100; step_counter++) {
		if (check_winner() == 1) {
			system("cls");
			break;
		}
		else {
			print_steps(step_counter);
			check_move();
		}

	}
	if (step_counter < 100) {
		blink_final_location();
		sleep(1000);
		system("cls");
		print_looser();
	}
	else {
		system("cls");
		gotoxy(4, 4);
		printf("You're loose");
	}
}

void sleep(unsigned int mseconds) { 
	clock_t goal = mseconds + clock(); 
	while (goal > clock()); 
} 