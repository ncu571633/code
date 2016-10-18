Implement a data structure supporting the following operations:

    Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
    Dec(Key) - Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. Key is guaranteed to be a non-empty string.
    GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
    GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".


class AllOne {
private: 
    map<string, int> m;
    set<pair<int, string>> s;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.count(key)) {
            s.erase(make_pair(m[key], key));
            m[key] ++;
        } else {
            m[key] = 1;
        }
        s.insert(make_pair(m[key], key));
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!m.count(key)) 
            return ;
        s.erase(make_pair(m[key], key));
        if(m[key]>1){
            m[key] --;
            s.insert(make_pair(m[key], key));
        } else {
            m.erase(key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(s.empty())
            return string("");
        return s.rbegin()->second;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(s.empty())
            return string("");
        return s.begin()->second;        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
