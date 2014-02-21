#include <iostream>
#include <bitset>
#include <climits>

using namespace std;



int main()
{
	int ints[] = {2, 3, 2, 5, 8, 1, 3};

	int min = INT_MAX;
	int max = 0;

	int size = sizeof(ints)/sizeof(ints[0]);
	for(int i=0; i<size; i++)
	{
		if(ints[i]>max)
			max = ints[i];
		if(ints[i]<min)
			min = ints[i];
	}	

	int size2 = max-min+1;
	bitset<10> b;
	for(int i=0; i<size2; i++)
	{
		int index = ints[i]-min;
		b[index] = 1;
	}

	for(int i=0; i<size; i++)
	{
		int index = ints[i]-min;
		if(b[index] == 1)
		{
			cout<< ints[i] << " ";
			b[index] = 0;
		}
	}
}
