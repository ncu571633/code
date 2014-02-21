/*
Question 2:
 
Setup:
Assume primitive Facebook. FB has Members.
class Member {
	String name;
	String email;
	list<Member> friends;
}
Question:
Code printSocialGraph(Member m). Direct friends of m are Level 1 friends. Friends of friends are level 2 friends.....and so on
Print level 1 friends first. Then print level 2 friends....and so on

void printSocialGraph (Member m){
	//Your code here
}
*/



#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;

class Member {
	public:
	string name;
    string email;
    list<Member> friends;
};

void printSocialGraph (Member m){
//Your code here
	//breath first search
    queue<Member> q;
    for(list<Member>::iterator it=m.friends.begin(); 
			it!=m.friends.end(); it++)
	{
		q.push(*it);
	}

	while(!q.empty())
	{
		//visit
		Member f = q.front();
		cout<<f.name<<endl;
		q.pop();
		//push m's friends into the queue
	    for(list<Member>::iterator it=f.friends.begin(); 
				it!=f.friends.end(); it++)
		{
			q.push(*it);
		}
	}



}

int main(int argc, char **argv)
{

    return 1;
}


