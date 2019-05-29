#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
LeftMove(char* arr,int n)
{
	char tmp = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		char tmp = *arr;
		int j = 0;
		while (*(arr + j + 1))
		{
			*(arr + j) = *(arr + j + 1);
			j++;
		}
		*(arr + j) = tmp;
	}

}

int main()
{
	char arr[] = "ABCDEF";
	int n = 0;
	printf("%s \n", arr);
	printf("请输入左旋的个数：\n");
	scanf("%d ", &n);
	LeftMove(arr, n);
	printf("左旋后的字符串：\n");
	printf("%s", arr);
	system("pause");
	return 0;
}









