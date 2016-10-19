/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples:

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.

For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

#include <set>
using namespace std;
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        large.insert(num);
        small.insert(*large.begin());
        large.erase(large.begin());
        if (large.size() < small.size()) {
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return large.size() > small.size() ? *large.begin() : 0.5 * (*small.rbegin() + *large.begin());
    }

private:
    multiset<long> small;
    multiset<long> large;
};

int main() {
    MedianFinder m;
    m.addNum(4);
    m.findMedian();
    m.addNum(2);
    m.addNum(6);
    m.findMedian();
    return 0;
}
