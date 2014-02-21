#include <iostream>
#include <vector>
using namespace std;
 
int binarySearch(vector<int>v, int l, int r, int n)
{
	int m = (l+r)/2;
	if(v[m] == n)
		return m;
	if(l == r && v[l] != n)
		return -1;
	
	//two parts: l -> m, m -> r
	if( v[l] <= v[m] )	//sorted left part 
	{
		if(v[l] <= n && n <= v[m])
			return binarySearch(v, l, m, n);
	}
	else//unsorted
	{
		if(v[l] <= n || n <= v[m])
			return binarySearch(v, l, m, n);
	}

	if( v[m] <= v[r] )	//sorted right part 
	{
		if(v[m] <= n && n <= v[r])
			return binarySearch(v, m, r, n);
	}
	else//unsorted
	{
		if(v[m] <= n || n <= v[r])
			return binarySearch(v, m, r, n);
	}
}
 
 int main()
 {
	 int myints[] = {6, 7, 8, 1, 2, 3, 4, 5};
	 vector<int> v(myints, myints + sizeof(myints) / sizeof(int));
	 cout << binarySearch(v, 0, v.size()-1, 8);
     return 0;
 }
