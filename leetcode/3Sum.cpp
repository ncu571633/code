#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

void twoSum(vector<vector<int> >&result, const vector<int>num, const int number, const int index)
{
	int begin = 0;
	int end = num.size()-1;
	vector<int>vtemp;
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
		if(num[begin]+num[end] == number)
		{
		//	cout << num[begin] << " " << num[end] << " " << -number << endl;
			vtemp.clear();
			vtemp.push_back(num[begin]), vtemp.push_back(num[end]), vtemp.push_back(-number);
			sort(vtemp.begin(), vtemp.end());
			//check whether the result exists
			int i = 0;
			for(i=0; i<result.size(); i++)
			{
				if(vtemp == result[i])
					break;
			}
			if(i==result.size())
				result.push_back(vtemp);
			begin++;
			continue;
		}
		if(num[begin] < number - num[end])
		{
			begin++;
			continue;
		}
		if(num[begin] > number - num[end])
		{
			end--;
			continue;
		}
	}
}

vector<vector<int> > threeSum(vector<int>num)
{
	sort(num.begin(), num.end());
	vector<vector<int> >result;
	for(int i = 0; i < num.size(); i++)
		twoSum(result, num, -num[i], i);
	return result;	
}

int main ()
{
	int S1[] = {-1, 0, 1, 2, -1, -4};
    vector<int> s (S1, S1+ sizeof(S1) / sizeof(int) );

//	sort(s.begin(), s.end());
//	twoSum(s, 0);

	threeSum(s);

}
