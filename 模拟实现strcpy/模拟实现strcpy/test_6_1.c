#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>
char* my_strcpy(char* dest,const char* src)
{
	char* cp = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return cp;
}

int main()
{
	char arr[80] = { 0 };
	char arr1[] = "hello bit";
	my_strcpy(arr, arr1);
	printf("string = %s", arr);
	system("pause");
	return 0;
}