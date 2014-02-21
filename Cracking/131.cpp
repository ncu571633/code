#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	fstream f;
	f.open("131.cpp");
	if(!f)
	{
		cerr<<"Can't open file."<< endl;
		exit(0);
	}
	int count = 0, k = 5;
	string str;
	while( getline(f, str) )
		count ++;
	
	cout << count << endl;

//	f.seekg (0, ios::beg);
	f.close();
	f.open("131.cpp");
	for(int i=0; i<count; i++)
	{
		string str;
		getline(f, str);
		if(i>count-k)
			cout << str << endl;
	}
	f.close();
}
