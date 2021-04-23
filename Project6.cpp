#include<iostream>
using namespace std;
void swap(int&, int&);
int main()
{
	int a = 10, b = 20;
	swap(a, b);
}
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
	cout << x << endl;
	cout << y << endl;
}
