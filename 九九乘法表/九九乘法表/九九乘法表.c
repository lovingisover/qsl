#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 

int main(){
	//���ѭ������,������  
	int i = 0;
	//�ڲ�ѭ������,������   
	int j = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%dx%d=%d\t", j, i, i*j);
		}
		//ÿ����������   
		printf("\n");
	}
	system("pause");
}