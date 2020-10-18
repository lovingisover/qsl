#define _CRT_SECURE_NO_WARNINGS 1
/*** Note: The returned array must be malloced, assume caller calls free().*/bool isOdd(int n){	return (n & 1) == 1;}int* exchange(int* nums, int numsSize, int* returnSize){	if ((nums == NULL) && (numsSize <= 0))	{		*returnSize = 0;		return NULL;	}	int *start = nums, *end = nums + numsSize - 1;	while (start < end)	{		while ((start < end) && (isOdd(*start)))		{			start++;		}		while ((start < end) && (!isOdd(*end)))		{			end--;		}		if (start < end)		{			int temp = *start;			*start = *end;			*end = temp;		}	}	*returnSize = numsSize;	return nums;}