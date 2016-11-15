/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/
#include "main.hpp"
class LRUCache{
private:
    map<int, list<int>::iterator> m;
    list<int> l;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.count(key) == 0)
            return -1;
        int value = *(m[key]);
        if(m[key] != l.begin()) {
            l.erase(m[key]);
            l.push_front(value);
            m[key] = l.begin();
        }
        cout<< "get" << key << endl;
        return value;
    }
    
    void set(int key, int value) {
       if(l.size() == size) {
           l.erase(prev(l.end()));
       }
       l.push_front(value);
       m[key] = l.begin();
       cout<< "set" << key << endl;
    }
};
