#define _CRT_SECURE_NO_WARNINGS 1
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
	m =	n % 10;
	n = n / 10;
	sum = m + DigitSum(n);
	}
	return sum;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	printf("请输入一个非负整数：\n");
	scanf("%d", &n);
	printf("sum = %d\n", DigitSum(n));
	system("pause");
	return 0;
}