#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	fstream f;
	f.open("1311.cpp");
	if(!f)
	{
		cerr << "Can't open file" << endl;
		exit(1);
	}

	string str[5], stemp;
	int index = 0;
	while(getline(f, stemp))
	{
		str[index] = stemp;
		index = (index+1)%5;
	}

	for(int i=index; ; i = (i+1)%5)
	{
		cout << str[i] << endl;
		if(i == index -1)
			break;
	}
}
