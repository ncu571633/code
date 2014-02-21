
/*
Question 3:

Write a function that converts an int into its alpha-numeric equivalent represented as a null terminated string. The function should accept an int as input and return a string as output. For instance, calling the function with an int value of 324 would return a null terminated string containing "324". Ensure that your function checks for appropriate boundary conditions and edge cases. Assume you cannot use any standard libraries (for example, no itoa or sprintf).

*/


#include <iostream>
#include <string>

using namespace std;

string myitoa(int i)
{
	if(i == 0)
		return string(1, '0');

	bool n = 0;
	if(i<0)
	{
		i = -i;
		n = true;
	}

	string s;
	while(i != 0)
	{
		s = string(1, '0'+i%10) + s;
		i = i/10;
	}

	if(n)
	{
		s = string(1, '-') + s;
	}

	return s;
}

int main()
{
	cout<<myitoa(1)<<endl;
	cout<<myitoa(-1)<<endl;
	cout<<myitoa(123)<<endl;
	cout<<myitoa(-112993)<<endl;
	cout<<myitoa(0)<<endl;
}
