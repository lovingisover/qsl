#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"game.h"
void game()
{
	char win = 0;
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL);
	displayboard(board, ROW, COL);
	while (1)
	{
		playmove(board, ROW, COL);
		displayboard(board, ROW, COL);
		win = checkboard(board,ROW,COL);
		if (win != ' ')
			break;
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		win = checkboard(board, ROW, COL);
		if (win != ' ')
			break;
	}
	if (win == '*')
	{
		printf("���Ӯ\n");
	}
	else if (win == '#')
	{
		printf("����Ӯ\n");
	}
	else if (win = 'Q')
	{
		printf("ƽ��\n");
	}
}
void menu()
{
	printf("******************************\n");
	printf("*****    1.play   ************\n");
	printf("*****    0.exit   ************\n");
	printf("******************************\n");
}
void test()
{
	int num = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
				break;
        default:
			printf("ѡ�����\n");
			break;
		}

	} while (num);
}
int main()
{
	test();
	system("pause");
	return 0;
}