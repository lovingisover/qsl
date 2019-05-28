#define _CRT_SECURE_NO_WARNINGS 1
void pritf(int n)
{
	if (n > 9)
	{
		pritf(n / 10);
	}
	printf("%d\n", n % 10);
}


int main()
{
	pritf(1234560);
	system("pause");
	return 0;
}