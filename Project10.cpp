#include<iostream>
using namespace std;
#include<cstring>
using namespace std;
int arr[3][3], brr[3][3], crr[3][3];
int Add()
{
	int* a;
	*a = arr[3][3] + brr[3][3];
	return *a;
}
int main()
{
	int* c;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	memcpy(brr, arr, sizeof(brr));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << c[i][j] << " ";
		}
	}
	*c = Add();
}
