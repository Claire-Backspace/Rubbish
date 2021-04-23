#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	const char* student[7] = { "1","2","3","4","5","6","7" };
	int first_number_student;
	first_number_student = rand() % 7 + 1;
	cout << *(student + first_number_student - 1) << endl;
}
