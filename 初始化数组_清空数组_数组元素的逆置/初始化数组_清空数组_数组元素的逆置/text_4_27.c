#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void init(int arr[], int x)
{
	memset(arr, 0, sizeof(arr[0]) * x);
}
void empty(int arr[], int x)
{
	memset(arr, 0, sizeof(arr[0]) * x);
}
void reverse(int arr[], int x)
{
	int left = 0;   
	int right = x - 1;
	while (left < right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
		init(arr, sz);
		empty(arr, sz);
		reverse(arr, sz);
		system("pause");
	return 0;
}