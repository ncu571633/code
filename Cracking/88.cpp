#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;


int check(vector<int>v)
{
	for(int i=0; i<v.size()-1; i++)
	{
	//	if(v[i] == v.back())
	//		return false;
	//	if(v.size()-1-i == abs(v[i]-v.back()))
	//		return false;
	}
	return true;
}

void nQueens(vector<int>v, int n, int N)
{
	if(n==N)
	{
		for(int i=0; i<v.size(); i++)
		{
			for(int j=0; j<v.size(); j++)
			{
				if(v[i] == j)
					cout << 1 << " ";
				else
					cout << 0 << " ";
			}
			cout << endl;
		}
		return ;
	}
	
	for(int i = 0; i<N; i++)
	{
		v.push_back(i);
		if( check(v) )
			nQueens(v, n+1, N);
		else
			v.pop_back();
	}
}

int main(int argc, char **argv)
{
	vector<int>v;
	nQueens(v, 0, atoi(argv[1]));
}
