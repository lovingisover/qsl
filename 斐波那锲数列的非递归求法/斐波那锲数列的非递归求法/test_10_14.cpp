#define _CRT_SECURE_NO_WARNINGS 1
int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int f0 = 0;
	int f1 = 1;
	int f2 = 0;
	f2 = f0 + f1;
	for (int i = 0; i < n - 1; ++i)
	{
		f2 = (f0 + f1) % 1000000007;
		f0 = f1;
		f1 = f2;
	}
	return f1;
}