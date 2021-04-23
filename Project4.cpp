#include<iostream>
using namespace std;
int main()
{
	int arr[3][2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}
	int sum = 0;
	int input = 0;
	int brr[6];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum += arr[i][j];
			brr[input] = arr[i][j];
			input++;
		}
	}
	cout << sum << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (brr[i] > brr[j])
			{
				int max = brr[i];
				brr[i] = brr[j];
				brr[j] = max;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		cout << brr[i] << " ";
	}
	cout << endl;
}