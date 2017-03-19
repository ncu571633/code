#include "379DesignPhoneDirectory.hpp"

int main(int argc, char** argv) {
    
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
    return 1;
}

// g++ main.cpp -g
// gdb a.out
// break 438FindAllAnagramsinaString.hpp:65
