#include <iostream>

using namespace std;

class a
{
};

class b
{
    void print() { cout << "b"; }
};

int main()
{
    cout << sizeof(a) << endl;  // 1
    cout << sizeof(b) << endl;  // 1

    return 1;
}
