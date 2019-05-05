#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu()
{
	printf("********************\n");
	printf("***** 1.play  *******\n");
	printf("***** 2.exit  *******\n");
	printf("********************\n");
}
void game()
{
	int input = 0;
	int num = rand()%100+1;
	while (1)
	{
		printf("请输入要猜的数字：");
		scanf("%d",&input);
		if (input > num)
		{ 
			printf("猜大了\n");
		}
		else if (input < num)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择<:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏/n");
			break;
		default:
			printf("输入错误,请重新输入！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}