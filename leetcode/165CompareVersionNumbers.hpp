/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
#include "main.hpp"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = version1.find('.'), index2 = version2.find('.');
        int v1 = atoi(version1.substr(0, index1).c_str());
        int v2 = atoi(version2.substr(0, index2).c_str());
        if(v1>v2)
            return 1;
        if(v1<v2)
            return -1;
        if(index1==-1 && index2==-1)
            return 0;
        if(index1==-1 && index2!=-1)
            return -1;
        if(index1!=1 && index2==-1)
            return 1;
        return compareVersion(version1.substr(version1.find('.')+1), 
            version2.substr(version2.find('.')+1));
    }
};
