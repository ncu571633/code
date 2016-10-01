#include <cassert>
#include <iostream>
#include <setjmp.h>
#include <stdlib.h>
#include <stdexcept>

bool doLongjmp = true;  // false for try catch 
const int THREADNO = 2;

jmp_buf signalEnv;

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
    RuntimeInfo(int m, int n)   { fm=m, fn=n; }
    inline void setEnv(jmp_buf *e) { fJBEnv=e;}
    inline jmp_buf* getEnv() { return fJBEnv;}
    inline pthread_t getTid(int i) { return fTids[i]; }
    int fm;
    int fn;
    int result[THREADNO];
  private:
    jmp_buf* fJBEnv;
    pthread_t fTids[THREADNO];
};

