#include <iostream>

using namespace std; 

int fun(int a, int b)
{
	if (a == 1 || b == 1)
		return 1;

	return fun(a-1, b) + fun(a, b-1);
}

int factorial(int n)
{
	if(n==1)
		return 1;
	return n*factorial(n-1);
}

int fun2(int a, int b)
{
//	(X-1 + Y-1)! / ((X-1)! * (Y-1)!)
	return factorial(a-1+b-1) / (factorial(a-1)*factorial(b-1));
}

int main()
{
	cout<< fun(2, 2) << fun2(2, 2) << endl;
	cout<< fun(3, 2) << fun2(3, 2) << endl;
	cout<< fun(3, 3) << fun2(3, 3) << endl;
	cout<< fun(4, 4) << fun2(4, 4) << endl;
}
