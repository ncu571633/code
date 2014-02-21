#include <iostream>
#include <forward_list>

using namespace std;

void add(forward_list<int> &l, int i)
{
	l.push_front(i);
//	l.insert_after(l.before_begin(), i);  //same as above
	l.sort();
}

void print(forward_list<int> l)
{
	for(forward_list<int>::iterator it=l.begin(); it!=l.end(); it++)
		cout<<*it<<endl;
}

int main()
{
	forward_list <int> l;
	add(l, 0);
	add(l, 0);
	add(l, -1);
	add(l, 2);

	print(l);
	return 0;
}

//g++ a.cpp -std=c++0x
