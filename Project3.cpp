#include<iostream>
using namespace std;
int main()
{
	class tty
	{
	public:
		tty()
		{
			cin >> vector_x;
		    cin >> vector_y;
	    }
		int vector_x = 0;
		int vector_y = 0;
		string state;
		void imshow()
		{
			cout << state << endl;
		}
		void operator*(tty & c)
		{
			if ((this->vector_x * c.vector_x + this->vector_y * c.vector_y) == 0)
				this->state = "no";
		}
	};
tty a, b;
a.operator *(b);
a.imshow();
return 0;
}