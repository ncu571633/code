/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = version1.find('.'), j = version2.find('.');
        int a = stoi(string(version1, 0, i));
        int b = stoi(string(version2, 0, j));
        if(a>b)
            return -1;
        if(a<b)
            return 1;
        a = stoi(string(version1, i+1, version1.size()-i));
        b = stoi(string(version2, j+1, version2.size()-i));
        if(a>b)
            return -1;
        if(a<b)
            return 1;
        return 0;
    }
};


int main()
{
	Solution s;
    s.compareVersion(string("0.1"), string("13.37"));
    return 0;
}
