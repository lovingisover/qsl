#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char arr[20] = { 0 };
	int i = 0;
	for (i = 0; i <= 2; i++)
	{
		printf("ÇëÊäÈëÃÜÂë£º\n");
		scanf("%s", arr);
		if (strcmp(arr, "123123") == 0)
		{
			printf("ÃÜÂëÕýÈ·£¬µÇÂ¼³É¹¦\n");
			break;
		}
		else
		{
			printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë£º\n");
		}
	}
	if (i == 3)
	{
		printf("Èý´ÎÃÜÂëÊäÈë´íÎó£¬µÇÂ¼Ê§°Ü\n");
	}
	system("pause");
	return 0;
}