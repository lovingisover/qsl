#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int a = 0;
	int tmp = 0;
	printf("������һ��������\n");
	scanf("%d ", &a);
	for (i = 31; i >= 0; i = i - 2)
	{
		tmp = (a >> i) & 1;
		printf("����λΪ:%d",tmp);
	}
	printf("\n");
	for (i = 30; i >= 0; i = i - 2)
	{
		tmp = (a >> i) & 1;
		printf("ż��λΪ:%d",tmp);

	}
	printf("\n");
	system("pause");
}