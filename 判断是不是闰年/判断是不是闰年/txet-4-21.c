#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int get_ar(int x)
{
	if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0))
		return 1;
	else
		return 0;
}
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (get_ar(year))
		{
			printf("%d\n", year);
		}
	}
	system("pause");
	return 0;
}