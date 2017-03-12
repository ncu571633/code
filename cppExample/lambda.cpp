#include <iostream>
#include <functional>

using namespace std;

int main()
{
    std::function<int(int)> factorial = [&] (int i) 
    { 
        return (i == 1) ? 1 : i * factorial(i - 1); 
    };

    cout<<factorial(5);
}

