#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int i = 0, j = 1;
	double x;
	double a, result = 0, b;
	cin >> x;
	while (fabs(result - sin(x)) >= 10e-10)
	{
		b = 1;
		for (int k = 1; k <= j; k++)
		{
			b = b * k;
		}
		a = pow(-1, i) * pow(x, j) / b;
		result = result + a;
		i++;
		j = j + 2;
	}
	//cout << sin(x) << endl;
	cout << setprecision(10) << std::fixed << sin(x) << endl;
	return 0;
}