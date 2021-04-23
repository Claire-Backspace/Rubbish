#include<iostream>
using namespace std;
int function(int n)
{
	if (n == 1)
	{
		return 10;
	}
	else if (n % 2 == 1)
	{
		return n + (function(n - 3)) / 2;
	}
	else
	{
		return n * function(n - 1);
	}
}
int main()
{
	int k;
	k = function(5);
	cout << k << endl;
}