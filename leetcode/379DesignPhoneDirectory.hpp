/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.

Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/

#include "main.hpp"

#if 0
class PhoneDirectory {
    private:
        set<int> s;
    public:  
        /** Initialize your data structure here 
          @param maxNumbers - The maximum numbers that can be stored in the phone directory. */  
        PhoneDirectory(int maxNumbers){ 
            for (int i=0; i<maxNumbers; i++)
                s.insert(i);
        }

        /** Provide a number which is not assigned to anyone. 
          @return - Return an available number. Return -1 if none is available. */
        int get() {
            if (s.empty())
                return -1;
            int ret = *s.begin();
            s.erase(s.begin());
            return ret;
        }

        /** Check if a number is available or not. */  
        bool check(int number) {
            return s.count(number);
        }

        /** Recycle or release a number. */  
        void release(int number) {
            s.insert(number);
        }

};

// O(1) time, O(n) space
class PhoneDirectory {
    private:
        queue<int> q;
        vector<int> v;
    public:  
        /** Initialize your data structure here 
          @param maxNumbers - The maximum numbers that can be stored in the phone directory. */  
        PhoneDirectory(int maxNumbers){  
            for (int i=0; i<maxNumbers; i++) {
                q.push(i);
            }
            v.resize(maxNumbers, 1);
        }

        /** Provide a number which is not assigned to anyone. 
          @return - Return an available number. Return -1 if none is available. */
        int get() {
            if(q.empty())
                return -1;
            int ret = q.front();
            q.pop();
            v[ret] = 0;
            return ret;
        }

        /** Check if a number is available or not. */  
        bool check(int number) {
            return v[number];
        }

        /** Recycle or release a number. */  
        void release(int number) {
            if (v[number])
                return ;
            v[number] = 1;
            q.push(number);
        }
};
#endif

// O(n) time, O(1) space
class PhoneDirectory {
    private:
        bitset<32> v;   // size: 32
        int size;
    public:  
        /** Initialize your data structure here 
          @param maxNumbers - The maximum numbers that can be stored in the phone directory. */  
        PhoneDirectory(int maxNumbers){
            size = maxNumbers;
            for(int i=0; i<maxNumbers; i++)
                v[i] = 1;
        }

        /** Provide a number which is not assigned to anyone. 
          @return - Return an available number. Return -1 if none is available. */
        int get() {
            for (int i=0; i<size; i++) {
                if(v[i]) {
                    v[i] = 0;
                    return i;
                }
            }
            return -1;
        }

        /** Check if a number is available or not. */  
        bool check(int number) {
            return v[number];
        }

        /** Recycle or release a number. */  
        void release(int number) {
            v[number] = 1;
        }
};

O(lgn) time
Binary search 

left     0 0 1 1 1 1 1 1
v        0 0 1 0 0 0 0 1
index    0 1 2 3 4 5 6 7

left     0 0 0 0 0 0 0 1
v        0 0 0 0 0 0 0 1    
index    0 1 2 3 4 5 6 7
    
v[2] -> 0
clear memory left (2, 6)    
    
class PhoneDirectory {
    private:
        bitset<32> v;   // size: 32
        int size;
        bit<32> left;
    public:  
        /** Initialize your data structure here 
          @param maxNumbers - The maximum numbers that can be stored in the phone directory. */  
        PhoneDirectory(int maxNumbers){
            size = maxNumbers;
            for(int i=0; i<maxNumbers; i++)
                v[i] = 1, left[i] = 1, right[i] = 1;
        }

        // find first 1 in [i, j] region
        int get(int i, j) {
            if(!v[j])
                return -1;
            int i=0, j=size-1;
            while(i<=j) {
                int k = (j-i)/2;
                if(v[k] = 1) {
                    v[k] = 0;
                    if(k!=size-1)
                        v[k+1]=v[k-1];
                    
                    return k;
                }
                if(v[k]==0)
            }        
        }
        
        /** Provide a number which is not assigned to anyone.         
        @return - Return an available number. Return -1 if none is available. */
        int get() {
            int first = get(0, size-1);
            int second = get(first, size-1);
            memset(v, first, second);
        }

        /** Check if a number is available or not. */  
        bool check(int number) {
            return v[number];
        }

        /** Recycle or release a number. */  
        void release(int number) {
            v[number] = 1;
            memset(v, number, size-1);
        }
};

    PhoneDirectory directory(3);
    cout << directory.get() << endl;
    cout << directory.get() << endl;
    cout << directory.check(2) << endl;
    cout << directory.get() << endl;
    cout << directory.check(2) << endl;
    cout << directory.get() << endl;
    directory.release(2);
    cout << directory.get() << endl;
    cout << directory.check(2) << endl;
