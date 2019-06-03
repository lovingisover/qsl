#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Storage(char*arr1, char* arr2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr1[i] = arr2[i];
	}

}
Link()
{
	char arr[] = "abcd";
	char arr1[] = "efg";
	char arr2[80] = { 0 };
	int size1 = strlen(arr);
	int size2 = strlen(arr1);
	Storage(&arr2[0], arr, size1);
	Storage(&arr2[4], arr1, size2);
	printf("%s\n", arr2);
}

int main()
{
	Link();
	system("pause");
	return 0;
}