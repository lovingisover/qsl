	#define _CRT_SECURE_NO_WARNINGS 1
	#include "game.h"
	void game()
	{
		char mine[ROWS][COLS] = { 0 };
		char show[ROWS][COLS] = { 0 };
		InitBoard(mine, ROWS, COLS, '0');//��ʼ�����������
		InitBoard(show, ROWS, COLS, '*');//��ʼ���������
		SetMine(mine, ROW, COL);//����
		//DisplayBoard(mine, ROW, COL);//��ӡ���������
		DisplayBoard(show, ROW, COL);//��ӡ�������
		SafeMine(mine, show, ROW, COL);//��һ�β�ը��
		FindMine(mine, show, ROW, COL);//����
	}
	void menu()
	{
		printf("**************************\n");
		printf("********^ɨ��С��Ϸ^******\n");
		printf("******    1.play    ******\n");
		printf("******    0.exit    ******\n");
		printf("**************************\n");
	}
	void test()
	{
		int input = 0;
		srand((unsigned int)time(NULL));//���������
		do//��Ϸ��ʼ���ظ���
		{
			menu();
			printf("��ѡ��:>");
			scanf("%d", &input);
			switch (input)
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
		} while (input);
	}
	int main()
	{
		test();
		return 0;
	}