Design and implement a TwoSum class. It should support the following operations:add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

class TwoSum {
public:
    void add(int n) {
        m[n]++;
    }

    bool find(int value) {
        for(auto a:m) {
            int t = value - a.first;
            if(t!=a.first&&m.count(t))
                return true;
            if(t==a.first && a.second>1)
                return true;
        }
        return false;
    }

private:
    unordered_map<int, int> m;
}
