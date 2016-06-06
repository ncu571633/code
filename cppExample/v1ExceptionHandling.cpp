/*
 error exception handling:
 setjmp...longjmp
 try...throw...catch.

 ./a.out 1 0    prints runtime error exception
 ./a.out 1 1    prints 1
   */

#include <cassert>
#include <iostream>
#include <setjmp.h>
#include <stdlib.h>
#include <stdexcept>
bool doLongjmp = true;  // false for try catch 

#define ENTER_CHECK_J(r)   \
    jmp_buf eEnv;      \
    if(doLongjmp) r->setEnv(&eEnv);       \
    if(doLongjmp && setjmp(eEnv)==0) {   \

#define LEAVE_CHECK_J()     \
    }

#define ENTER_CHECK_N(r)    \
    try {                   \

#define LEAVE_CHECK_N()     \
    } catch(std::runtime_error& e) { \
        std::cout<< e.what();    \
    } catch(...) {          \
        std::cout<< "unhandled exception";  \
        assert(true);       \
    }                       \

class RuntimeInfo {
  public:
    inline void setEnv(jmp_buf *e) { fJBEnv=e;}
    inline jmp_buf* getEnv() { return fJBEnv;}
  private:
    jmp_buf* fJBEnv;
};

int proc(int n, int m, RuntimeInfo *r)
{
    if(!m)
    {
        std::string errMsg("divide/0 runtime error.\n");
        if(doLongjmp) {
            std::cout<< errMsg;
            longjmp(*(r->getEnv()), -1);
        } else{
            throw(std::overflow_error(errMsg));
        }
    }
    return n/m;
}


int main(int argc, char **argv)
{
    if(argc != 3)
        return -1;

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    
    RuntimeInfo *r = new RuntimeInfo();
    
    if(doLongjmp) {
        ENTER_CHECK_J(r);
        std::cout << proc(n, m, r) << "\n";
        LEAVE_CHECK_J();
    }
    else {
        ENTER_CHECK_N(r);
        std::cout << proc(n, m, r) << "\n";
        LEAVE_CHECK_N();
    }

    delete(r);
    return 0;
}
