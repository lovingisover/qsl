#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	system("pause");
	return 0;
}
/*class Date
{
	
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d) {
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d(2018, 18, 23);
	cin >> d;
	cout << d << endl;
	system("pause");
	return 0;
}
/*class Data
{
	friend ostream& operator<<(ostream& _cout, const Data& d);
	friend istream& operator>>(istream& _cin, Data& d);
public:
	Data(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Data& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Data& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return cin;
}
int main()
{
	Data d;
	cin >> d;
	cout << d << endl;
	system("pause");
	return 0;
}
/*class B
{
public:
	B(int b = 0)
		:_b(b)
	{}
	int _b;
};
class A {
public:
	void Print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	// 非静态成员变量，可以在成员声明时给缺省值。
	int a = 10;
	B b = 20;
	int* p = (int*)malloc(4);
	static int n;
};
int A::n = 10;
int main()
{
	A a;
	a.Print();
	return 0;
}
/*class A {
public: A() { ++_scount; }
		A(const A& t) { ++_scount; }
		static int GetACount() { return _scount; }
private:
	static int _scount;
};
int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}
void main()
{
	TestA();
	system("pause");
}*/