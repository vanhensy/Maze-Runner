#include <stdio.h>
#include <windows.h>
#include <stdbool.h>


int MazeEncrypted[20][62];

// Basement for Read Data in txt file
enum { SUCCESS, FAIL, MAX_LENGTH = 120 };
void ReturnLine(FILE *fptr, int size);
void DataRead(FILE *fptr);
int ErrorMsg(char *str);

void DataRead(FILE *fptr)
{
	char buff[MAX_LENGTH];
	fgets(buff, MAX_LENGTH, fptr);
	printf("\t %s", buff);
}

int ErrorMsg(char *str)
{
	printf("Problem, cannot open %s.\n", str);
	return FAIL;
}


void ReturnLine(FILE *fptr, int size)
{
	for (int i = 0; i < size; i++) {
		DataRead(fptr);
	}
}



void print_intro() {
	FILE *intro;
	errno_t err = 0;
	char filename[] = { "intro.txt" };
	int reveal = "SUCCESS";
	err = fopen_s(&intro, filename, "r");
	if (err != 0) {
		reveal = ErrorMsg(filename);
	}
	else
	{
		ReturnLine(intro, 9);
	}
}

void print_maze() {
	FILE *maze;
	errno_t err = 0;
	char filename[] = { "maze.txt" };
	int reveal = "SUCCESS";
	err = fopen_s(&maze, filename, "r");
	if (err != 0) {
		reveal = ErrorMsg(filename);
	}
	else
	{
		gotoxy(0, 3);
		ReturnLine(maze, 19);
	}
}

void print_looser() {
	FILE *looser; 
	char filename[] = { "looser.txt" };
	errno_t err = 0; 
	int reveal = "SUCCESSS";
	err = fopen_s(&looser, filename, "r");
	if (err != 0) {
		reveal = ErrorMsg(filename);
	}
	else {
		gotoxy(0, 7);
		ReturnLine(looser, 8);
	}
}

void print_winner() {
	FILE *winner;
	errno_t err = 0;
	char filename[] = { "winner.txt" };
	int reveal = "SUCCESS";
	err = fopen_s(&winner, filename, "r");
	if (err != 0) {
		reveal = ErrorMsg(filename);
	}
	else
	{
		gotoxy(0, 7);
		ReturnLine(winner, 8);
	}
}

int analysis_maze() {
	FILE *maze;
	char filename[] = { "maze.txt" };
	fopen_s(&maze, filename, "r");
	char buff[MAX_LENGTH];
	for (int i = 0; i < 20; i++) {
		fgets(buff, MAX_LENGTH, maze);
		for (int f = 0; f < 62; f++) {
			if (buff[f] == '#') {
				MazeEncrypted[i][f] = 0;
				MazeEncrypted[i][f + 1] = 0;
				f++;
			}
			else {
				MazeEncrypted[i][f] = 1;
				MazeEncrypted[i][f + 1] = 1;
			}
		}
	}
	return MazeEncrypted[20][62];
}

