#include <stdio.h>
#include <windows.h>
#define MAX 100

void print_matrix()
{
	char grid[MAX][MAX];
	int i, j, row, col;

	printf("Please enter your grid size: ");
	scanf_s("%d %d", &col, &row);
	system("cls");
	
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			grid[i][j] = '#';
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}

	getch();
}
