#include "291WordPatternII.hpp"

int main(int argc, char** argv) {
    
    Solution s;
    cout<<s.wordPatternMatch("abab", "redblueredblue")<<endl;   //1
    cout<<s.wordPatternMatch("aaaa", "asdasdasdasd")<<endl; // 1
    cout<<s.wordPatternMatch("aabb", "xyzabcxzyabc")<<endl; // 0
    return 1;
}

// g++ main.cpp -g
// gdb a.out
// break 438FindAllAnagramsinaString.hpp:65
