#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

void twoSum(const vector<int>num, const int index, const int target, int&result)
{
	int begin = 0;
	int end = num.size()-1;
	while(begin < end)
	{
		if(begin == index)
		{
			begin ++ ;
			continue;
		}	
		if(end == index)
		{
			end --;
			continue;
		}
		int temp = num[begin]+num[end]+num[index]; 
	//		cout << num[begin] << " " << num[end] << " " << num[index] << endl;
		if(result==INT_MAX || abs(temp-target) <= abs(target-result))
		{
			result = temp;
			if(result == target)
				return;
		}
		if(num[begin]+num[end]+num[index] < target)
			begin++;
		else
			end--;
		continue;
	}
}

int threeSumClosest(vector<int> &num, int target) 
{
	sort(num.begin(), num.end());
	int result = INT_MAX;
	for(int i = 0; i < num.size(); i++)
	{
		twoSum(num, i, target, result);
	//	cout<<i << " " << num[i] << endl;
		if(target == result)
			return result;
	}
	return result;        
}

int main ()
{
	int S1[] = {1,1,-1,-1,3};
    vector<int> s (S1, S1+ sizeof(S1) / sizeof(int) );

//	sort(s.begin(), s.end());
//	twoSum(s, 0);
	int target = -1;
	cout << threeSumClosest(s, target) << endl;
}
