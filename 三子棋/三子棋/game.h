#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__
#define ROW 3
#define COL 3
void Initboard(char board[ROW][COL],int row,int col);
void displayboard(char board[ROW][COL],int row, int col);
void playmove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
char checkboard(char board[ROW][COL], int row, int col);
#endif 