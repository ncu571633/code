// task string
// same task needs cooldown
// task: 12323 cooldown: 3   1 2 3 _ _ 2 3  -> 7
// task: 1242353 cooldown: 4  1 2 4 _ _ _ 2 3 5 _ _ _ 3  -> 13

#include "main.hpp"

int GetTime(string s, int coolDown)
{
    unordered_map<char, int> m;
    int ret = 0;
    for(int i=0; i<(int)s.size(); i++) {
        if(!m.count(s[i])) {
            ret ++;
        } else {
            if(ret+1-m[s[i]] > coolDown) {
                ret = ret+1;
            } else {
                ret = m[s[i]] + coolDown + 1;
            }
        }
        m[s[i]] = ret;
    }
    return ret;
}

int main() {
    cout<<GetTime("12323", 3)<<endl;
    cout<<GetTime("1242353", 4)<<endl;
}
