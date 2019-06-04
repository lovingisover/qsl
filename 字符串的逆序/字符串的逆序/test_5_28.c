#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int my_strlen(const char* str)
{
	assert(str != NULL);
	int count = 0;
	while (*str)
	{
		count++;
	}
	return count;
}
void reverse(char* strart, char* end)
{
	assert(strart != NULL);
	assert(end != NULL);
	while (strart < end)
	{
		char* tmp = *end;
		*end = *strart;
		*strart = tmp;
		strart++;
		end--;
	}
}
void str_reverse(char *arr)
{
	int len = my_strlen(arr);
	reverse(arr, arr + len - 1);
	while (*arr)
	{
		char *tmp = arr;
		while ((*arr != ' ') && (*arr != '\0'))
		{
			arr++;
		}
		reverse(tmp, arr - 1);
		if (*arr == ' ')
		{
			arr++;
		}
	}

}
int main()
{
	char arr[] = "student a am i";
	str_reverse(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}
