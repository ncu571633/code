#include <iostream>
using namespace std;

template <typename Type> // this is the template parameter declaration
Type maxa(Type tX, Type tY)
{
    return (tX > tY) ? tX : tY;
}


int main () {
  cout<< maxa(1, 2) << endl;
  return 0;
}
