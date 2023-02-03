#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			board[i][j] = set;
}

void DispBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col,int count)
{

	while (count)
	{
		int x = rand()%row+1, y = rand()%col+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0,s = 0;
	for (i = x - 1; i <= x + 1; i++)
		for (j = y - 1; j <= y + 1; j++)
		{
			s += mine[i][j] - '0';
		}
	return s;
}

void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int count)
{
	int x = 0, y = 0, win = row*col - count;
	int i = 0, j = 0;
	while (win)
	{
		scanf("%d %d", &x, &y);
		if (mine[x][y] == '1')
		{
			DispBoard(show, ROW, COL);
			printf("ÂäÃü\n");
			break;
		}
		else if (show[x][y] == '*')
		{
			show[x][y] = get_mine_count(mine, x, y)+'0';
			//if (show[x][y] == 0)
			win--;
			DispBoard(show, ROW, COL);
		}
	}
	if (!win)
		printf("win\n");
}