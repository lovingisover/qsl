#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
int main()
{
	int n = 0;
	int i = 0;
	int sum = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum = sum*i;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}
