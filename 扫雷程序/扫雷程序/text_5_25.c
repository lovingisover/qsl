	#define _CRT_SECURE_NO_WARNINGS 1
	#include "game.h"
	void game()
	{
		char mine[ROWS][COLS] = { 0 };
		char show[ROWS][COLS] = { 0 };
		InitBoard(mine, ROWS, COLS, '0');//初始化设计者棋盘
		InitBoard(show, ROWS, COLS, '*');//初始化玩家棋盘
		SetMine(mine, ROW, COL);//布雷
		//DisplayBoard(mine, ROW, COL);//打印设计者棋盘
		DisplayBoard(show, ROW, COL);//打印玩家棋盘
		SafeMine(mine, show, ROW, COL);//第一次不炸死
		FindMine(mine, show, ROW, COL);//排雷
	}
	void menu()
	{
		printf("**************************\n");
		printf("********^扫雷小游戏^******\n");
		printf("******    1.play    ******\n");
		printf("******    0.exit    ******\n");
		printf("**************************\n");
	}
	void test()
	{
		int input = 0;
		srand((unsigned int)time(NULL));//调用随机数
		do//游戏开始，重复玩
		{
			menu();
			printf("请选择:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误\n");
				break;
			}
		} while (input);
	}
	int main()
	{
		test();
		return 0;
	}