#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int binary_search(int arr[], int k,int left,int right)
{
	while (left <= right)
	{
		
		int mid = left + (right - left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}

		else
			return mid;
	}
	  return -1;

}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	int ret = binary_search(arr, k, left,right);//只需要将刚才的参数sz，改成左右下标传到函数中就可以算任意长度的数组了，也就是说现在可以直接将左右下标改成具体的数字。
	if (sz == -1)
	{
		printf("哎呀，找不到了");
	}
	else
	{
		printf("找到了，下标是：%d", ret);
	}
	system("pause");
	return 0;
}