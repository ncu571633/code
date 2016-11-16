#include "44WildcardMatching.hpp"

int main(int argc, char** argv) {
    Solution s;
    s.isMatch(string("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"), string("a*******b"));

    return 1;
}

// g++ main.cpp -g
// gdb:
// break 438FindAllAnagramsinaString.hpp:65
