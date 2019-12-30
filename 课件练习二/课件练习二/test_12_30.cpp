#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test():" << this <<endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test2()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}
void Test3()
{
	Test* p1 = new Test;
	delete p1;

	Test* p2 = new Test[10];
	delete[] p2;
}
void main()
{
	Test2();
	Test3();
	system("pause");
}











/*void main()
{
	int num1[10] = { 1, 2, 3, 4 };
	char chd[] = "abcd";
	char* pchar = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	cout << sizeof(num1) << endl;
	cout << sizeof(chd) << endl;
	cout << strlen(chd) << endl;
	cout << sizeof(pchar) << endl;
	cout << strlen(pchar) << endl;
	cout << sizeof(ptr1) << endl;
	system("pause");
}*/