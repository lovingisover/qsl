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
		printf("���������룺\n");
		scanf("%s", arr);
		if (strcmp(arr, "123123") == 0)
		{
			printf("������ȷ����¼�ɹ�\n");
			break;
		}
		else
		{
			printf("����������������룺\n");
		}
	}
	if (i == 3)
	{
		printf("��������������󣬵�¼ʧ��\n");
	}
	system("pause");
	return 0;
}