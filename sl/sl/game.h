#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW  9
#define COL  9
#define ROWS  ROW+2
#define COLS  COL+2
#define COUNT  10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DispBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col, int count);
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int count);