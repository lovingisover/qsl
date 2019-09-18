#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Count_one_bit(unsigned int set)
{
	int count = 0;
	while (set)
	{
		if (set%2 == 1)
			count++;
		set = set/2;

	}
	return count;
}

int main()
{
	int set = 0;
	int ret = 0;
	printf("请输入一个数：\n");
	scanf("%d ", &set);
	ret = Count_one_bit(set);
	printf("这个数二进制中一得个数为：%d\n", ret);
	system("pause");
	return 0;
}