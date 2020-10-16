#define _CRT_SECURE_NO_WARNINGS 1
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* printNumbers(int n, int* returnSize)
{
	int length = 0;

	while (n--)
	{
		length = length * 10 + 9;
	}

	int *arr = (int*)malloc(sizeof(int)*length);

	for (int i = 0; i < length; ++i)
	{
		arr[i] = i + 1;
	}
	*returnSize = length;
	return arr;
}
