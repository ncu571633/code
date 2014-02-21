// constructing priority queues
#include <iostream>
#include <queue>
using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main ()
{
  int myints[]= {10,60,50,20};

  priority_queue<int> first;
  priority_queue<int> second (myints,myints+4);
  priority_queue< int, vector<int>, greater<int> > third (myints,myints+4);

  // using mycomparison:
  priority_queue< int, vector<int>, mycomparison > fourth;

  typedef priority_queue<int,vector<int>,mycomparison> mypq_type;
  mypq_type fifth (mycomparison());
  mypq_type sixth (mycomparison(true));

  return 0;
}
