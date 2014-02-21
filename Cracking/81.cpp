#include <iostream>

using namespace std;

int fun(int n)
{
	if( n==0 )
		return 0;
	if( n==1 )
		return 1;
	return fun(n-1) + fun(n-2);
}

int fun2(int n)
{
	if( n == 0)
		return 0;
	if( n == 1)
		return 1;
	int a = 0, b = 1, c = 1;
	for(int i=1; i<n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	cout << fun(8) << endl;
	cout << fun2(8) << endl;
}

