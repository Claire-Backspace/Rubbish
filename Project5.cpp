#include<iostream>
using namespace std;
class Date
{
public:
	Date(int, int, int);
	~Date();
	void SetDate(int y, int m, int d);
	void IsLeapYear()const;
	void PrintDate()const;
private:
	int year, month, day;
};
Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	cout << year << "/" << month << "/" << day << ":Date object initialized." << "\n";
}
Date::~Date()
{
	cout << year << "/" << month << "/" << day << ":Date object destroyed." << "\n";
}
void Date::SetDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::IsLeapYear()const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		cout << "Is leap year.\n";
	else
		cout << "Is not leap year.\n";
}
void Date::PrintDate()const
{
	cout << year << "/" << month << "/" << day << endl;
}
int main()
{
	Date d1(2000, 1, 1);
	Date d2(2000, 1, 3);
	d1.SetDate(1999, 6, 15);
	d1.PrintDate();
	d1.IsLeapYear();
	d2.SetDate(2000, 9, 9);
	d2.PrintDate();
	d2.IsLeapYear();          //首先创建的对象将最后析构
}