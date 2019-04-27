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
	int ret = binary_search(arr, k, left,right);//ֻ��Ҫ���ղŵĲ���sz���ĳ������±괫�������оͿ��������ⳤ�ȵ������ˣ�Ҳ����˵���ڿ���ֱ�ӽ������±�ĳɾ�������֡�
	if (sz == -1)
	{
		printf("��ѽ���Ҳ�����");
	}
	else
	{
		printf("�ҵ��ˣ��±��ǣ�%d", ret);
	}
	system("pause");
	return 0;
}