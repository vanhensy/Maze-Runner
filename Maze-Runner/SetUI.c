#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void add_color(bool condition, int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	if (condition) {
		switch (color)
		{
		case 1:
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			break;
		default:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			break;
		}

	}
	else {
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	}
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short col, short row) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { col, row };
	SetConsoleCursorPosition(h, position);
}
