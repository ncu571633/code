
#include <signal.h>
#include <pthread.h>
#include "exception.hpp"

void idle()
{
    for (int j = 0; j < 10000000; j++) {
        for (int i = 0; i < 1000000; i++);
    }
}

void cntl_c_handler(int dummy)
{
    std::cout<< "You just typed cntl-c\n";
	longjmp(signalEnv); 
    signal(SIGINT, cntl_c_handler);
}

void proc(void *ar)
{
    RuntimeInfo *r = (RuntimeInfo *)ar;
    signal(SIGINT, cntl_c_handler);
    
    if(!r->fm)
    {
        std::string errMsg("divide/0 runtime error.\n");
        if(doLongjmp) {
            std::cout<< errMsg;
            longjmp(*(r->getEnv()), -1);
        } else{
            throw(std::overflow_error(errMsg));
        }
    }
    //idle();
    r->result[] = r->fn/r->fm;
}


int main(int argc, char **argv)
{
    if(argc != 3)
        return -1;

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    
    RuntimeInfo *r = new RuntimeInfo(m, n);
    
    if(doLongjmp) {
        ENTER_CHECK_J(r);
        for(int i=0; i<THREADNO; i++) {
            pthread_create(r->getTid[i], NULL, proc, (void*)r);
            std::cout << r->result[i] << "\n";
        }

        for(int i=0; i<THREADNO; i++) {
            void *retval;
            pthread_join(r->getTid[i], &retval);
        }
        LEAVE_CHECK_J();
    }
    else {
        ENTER_CHECK_N(r);
        proc(r);
        LEAVE_CHECK_N();
    }

    delete(r);
    return 0;
}
