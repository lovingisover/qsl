#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, j;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j<i; j++)
		{
			if (i%j == 0)
				break;
		}
		if (i == j)
		{
			printf("%d\n", i);
			count++;

		}
	}
	printf("\ncount=%d\n", count);
	getchar();
	return 0;
}
