#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d",&n);
	ret = fib(n);
	printf("第n个斐波那锲数是：%d\n",ret);
	system("pause");
	return 0;
}
