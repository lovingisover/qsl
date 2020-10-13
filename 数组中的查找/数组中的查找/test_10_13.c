#define _CRT_SECURE_NO_WARNINGS 1
int findRepeatNumber(int* nums, int numsSize){
	unsigned char remark[numsSize];
	memset(remark, 0, numsSize);
	for (int i = 0; i < numsSize; ++i){
		if (remark[nums[i]])
			return nums[i];
		remark[nums[i]] = 1;
	}
	return -1;
}