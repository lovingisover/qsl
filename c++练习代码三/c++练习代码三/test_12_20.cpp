#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*class A1
{
public:
	void f1(){}
private:
	int _a;
};
class A2
{
public:
	void f2(){}
};
class A3
{};
int main()
{
	cout << "result is:" << sizeof(A1) << endl;
	cout << "result is:" << sizeof(A2) << endl;
	cout << "result is:" << sizeof(A3) << endl;
	system("pause");
	return 0;
}*/
/*class Data
{
public:
	void Display()
	{
		cout << _year << "_" << _month << "_" << _day << endl;
	}
	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Data d1, d2;
	d1.SetData(2018, 5, 1);
	d2.SetData(2018, 7, 1);
	d1.Display();
	d2.Display();
	system("pause");
	return 0;
}*/
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	Data* p = NULL;
	p->PrintA();
	p->Show();

}

