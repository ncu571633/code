#include <iostream>
#include <string>

using namespace std;

void strper(string str, int b, int e, string stemp)
{
	if(b>e)
		return ;
	cout << str[b] << endl;
	if(b==e)
	{
		cout << stemp << endl;
		cout << stemp+str[e] << endl;
		cout << str[e] + stemp << endl;
	}
	strper(str, b+1, e, stemp+str[b]);
	strper(str, b+1, e, str[b]+stemp);
}

int main()
{
	string str("hello");
	string stemp;
	strper(str, 0, str.size()-1, stemp);
}
