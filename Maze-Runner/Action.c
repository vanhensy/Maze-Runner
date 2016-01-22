#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int home_x = 12, home_y = 4;
extern int MazeEncrypted[20][62];

void print_position(x, y) {
	gotoxy(42, 1);
	printf("X-Position: %i", x);
	gotoxy(58, 1);
	printf("Y-Position: %i", y);
}
int check_move() {

	int KEY_PRESSED;
	KEY_PRESSED = _getch();
	if (KEY_PRESSED == 0 || KEY_PRESSED == 224) {
		switch (_getch())
		{
		case 72:
			system("cls");
			print_maze();
			if (MazeEncrypted[home_y - 4][home_x - 9] != 0) {
				func_go_up();
			}
			else {
				print_current_location();
			}
			print_position(home_x, home_y);

			return home_x, home_y;
			break;
		case 80:
			system("cls");
			print_maze();

			if (MazeEncrypted[home_y - 2][home_x - 9] != 0) {
				func_go_down();
			}
			else {
				print_current_location();
			}
			print_position(home_x, home_y);
			return home_x, home_y;
			break;
		case 77:
			system("cls");
			print_maze();
			if (MazeEncrypted[home_y - 3][home_x - 7] != 0) {
				func_go_right();
			}
			else {
				print_current_location();
			}
			print_position(home_x, home_y);
			return home_x, home_y;
			break;
		case 75:
			system("cls");
			print_maze();

			if (MazeEncrypted[home_y - 3][home_x - 11] != 0) {
				func_go_left();
			}
			else {
				print_current_location();
			}
			print_position(home_x, home_y);
			return home_x, home_y;
			break;
		default:
			break;
		}
	}

}

void check_winner() {
	if (home_x == 26 && home_y == 16) {
		return 1;
	}
	else {
		return 0;
	}
}

int print_current_location() {
	add_color(true, 2);
	gotoxy(home_x, home_y);
	printf("%c", 219);
	add_color(false, NULL);
}

int blink_final_location() {
	print_maze();
	for (int frequency = 0; frequency < 3; frequency++) {
		add_color(true, 0);
		print_maze();
		gotoxy(home_x, home_y);
		printf("%c", 219);
		sleep(100);
		add_color(true, 1);
		print_maze();
		gotoxy(home_x, home_y);
		printf("%c", 219);
		sleep(100);
		add_color(true, 2);
		print_maze();
		gotoxy(home_x, home_y);
		printf("%c", 219);
		sleep(100);
	}
	add_color(false, NULL);
}

void AutoMove() {
	for (int step_counter = 0; step_counter < 100; step_counter++) {
		int random_direction = rand() % 4; 
		switch (random_direction)
		{
		case 1:
			func_go_up();
			break;
		case 2:
			func_go_down();
			break;
		case 3:
			func_go_right();
			break;
		case 4:
			func_go_left();
			break;
		default:
			break;
		}
	}
}

int func_go_up() {
	add_color(true, 1);
	home_y--;
	gotoxy(home_x, home_y);
	printf("%c", 219);
	add_color(false, NULL);
}

int func_go_down() {
	add_color(true, 1);
	home_y++;
	gotoxy(home_x, home_y);
	printf("%c", 219);
	add_color(false, NULL);
}

int func_go_left() {
	add_color(true, 1);
	home_x -= 2;
	gotoxy(home_x, home_y);
	printf("%c", 219);
	add_color(false, NULL);
}

int func_go_right() {
	add_color(true, 1);
	home_x += 2;
	gotoxy(home_x, home_y);
	printf("%c", 219);
	add_color(false, NULL);
}