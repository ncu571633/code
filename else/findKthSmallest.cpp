#include <iostream>
#include <queue>
using namespace std;
const int n = 4;
int main ()
{
	int numbers[]= {10,60,50,20};
	priority_queue<int> pq(numbers, numbers+n);
/*	priority_queue<int> pq;
	for(register int i=0; i<4; i++)
		pq.push(numbers[i]);
*/
	while(!pq.empty())
	{
		cout<<pq.top()<<endl;
		pq.pop();
	}

	return 0;
}
