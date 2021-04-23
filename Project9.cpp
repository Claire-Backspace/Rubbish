#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 0;
	a = (b = 3) = 1;
	cout << b << endl;
}