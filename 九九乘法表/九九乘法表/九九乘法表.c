#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 

int main(){
	//外层循环变量,控制行  
	int i = 0;
	//内层循环变量,控制列   
	int j = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%dx%d=%d\t", j, i, i*j);
		}
		//每行输出完后换行   
		printf("\n");
	}
	system("pause");
}