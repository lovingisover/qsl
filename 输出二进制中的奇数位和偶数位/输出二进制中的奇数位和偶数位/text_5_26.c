#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int a = 0;
	int tmp = 0;
	printf("请输入一个整数：\n");
	scanf("%d ", &a);
	for (i = 31; i >= 0; i = i - 2)
	{
		tmp = (a >> i) & 1;
		printf("奇数位为:%d",tmp);
	}
	printf("\n");
	for (i = 30; i >= 0; i = i - 2)
	{
		tmp = (a >> i) & 1;
		printf("偶数位为:%d",tmp);

	}
	printf("\n");
	system("pause");
}