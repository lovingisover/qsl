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
		printf("������Ҫ�µ����֣�");
		scanf("%d",&input);
		if (input > num)
		{ 
			printf("�´���\n");
		}
		else if (input < num)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�¶���\n");
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
		printf("��ѡ��<:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ/n");
			break;
		default:
			printf("�������,���������룡\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}