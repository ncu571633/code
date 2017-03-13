// compare String
// char > digit
// abc9 < abc123
// abc > ab9
// abc1 == abc0001

#include "main.hpp"

bool isDigit(char c)
{
    return '0'<=c && c<='9';
}
int stringComparator(string a, string b)
{
    if(a.empty() && !b.empty())
        return -1;
    if(!a.empty() && b.empty())
        return 1;
    
    for(size_t i=0; i<a.size()&&i<b.size(); i++) {
        if(isDigit(a[i]) && isDigit(b[i])) {
            size_t j=i, t1=0, t2=0;
            while(i<a.size() && isDigit(a[i])) {
                t1=t1*10+a[i]-'0';
                i++;
            }
            while(j<b.size() && isDigit(b[j])) {
                t2=t2*10+b[j]-'0';
                j++;
            }
            return t1-t2;
        }
        if(!isDigit(a[i]) && !isDigit(b[i]))
            return a[i]-b[i];
        if(!isDigit(a[i]) && isDigit(b[i]))
            return 1;
        if(isDigit(a[i]) && !isDigit(b[i]))
            return -1;

    }
    return 0;
}

int main()
{
    cout<<stringComparator("abc9", "abc123")<<endl;
    cout<<stringComparator("abc9", "abc012")<<endl;
    cout<<stringComparator("abc9", "abc002")<<endl;
    cout<<stringComparator("abc", "ab9")<<endl;
    cout<<stringComparator("abcd", "abcd")<<endl;
    cout<<stringComparator("abcd1a", "abcd1a")<<endl;
    cout<<stringComparator("abcd9a", "abcd123a")<<endl;
    cout<<stringComparator("abc1", "abcd0001")<<endl;
}
