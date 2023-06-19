Exception is not handled, C++ run time calls std::terminate(). 
********************************************************************************

Enable exception handling(GCC enable by default)
    Generates extra code needed to propagate exceptions. 
    to generate frame unwind information for all functions, which can produce significant data size overhead, although it does not affect execution. 

********************************************************************************
noexcept:
    Mark a function as noexcept only if all the functions that it calls, either directly or indirectly, are also noexcept or const. 
    The compiler doesn't necessarily check every code path for exceptions that might bubble up to a noexcept function. 
    If an exception does exit the outer scope of a function marked noexcept, std::terminate is invoked immediately,

********************************************************************************

  

https://www.codeproject.com/Articles/2126/How-a-C-compiler-implements-exception-handling
https://llvm.org/docs/ExceptionHandling.html#exception-tables
How try-catch is implemented (depends on the compiler):

Define exception object which is created in one function, destroyed in a caller thereof. So, it's typically not feasible to create the object on the stack. Object should not be big

Transfer of control Two ways
1. Code approach
(1) early days: setjmp, longjump to return to a previous context: stack pointer (sp), frame pointer (fp), and program counter (pc).
    Longjmp() resets the registers to the values saved in env
    longjmp() ``returns'' to the state of the program when setjmp() was called. 

(2) Record enough information in the stack itself to unwind the stack: 
	basically a list of destructors to run and exception handlers that might catch the exception. 
	When an exception happens, run back the stack executing those destructors until you find a matching catch.
	Register each constructed object together with its destructor for later destruction. (link list)
	Restore the execution environment associated with the catch clause
(3) time overhead: stack the execution context
	even no exceptions are thrown, need to keep exception handling stack for automatic/tempaory/partially constructed obj


2. table approach: uses compiler-generated static tables
moves this information into tables outside the stack. 
when an exception occurs, the call stack is used to find out which scopes are entered but not exited. Those are then looked up in the static tables to determine where the thrown exception will be handled, and which destructors run in between. 
This means there is less exception overhead on the stack; return addresses are needed anyway. 
The tables are extra data, but the compiler can put them in a demand-loaded segment of the program.
advantage: no runtime cost. All associated run-time costs occur only when an exception is thrown

added branches
	branch prediction becomes harder
	register pressure might increase substantially

Compiler may reorder the instruction for optimization. 
Because of try-catch, 
Each object needs to be fully initialized before any exception could lead to its destruction, limiting the reordering of instructions (e.g. from an inlined constructor) across potentially throwing calls. 
Likewise, an object must be completely destroyed before any possible subsequent exception.

table is large: download the program and load it into RAM, cache friendly? 



Conclusion:
    cost is extra space (tables/handlers) whether or not exception are thrown.
    parsing the table and executing the handlers when an exception is thrown


********************************************************************************

Exception safety is the state of code working correctly when exceptions are thrown

vector

No-throw guarantee: 
    No-throw guarantee, also known as failure transparency: Operations are guaranteed to succeed and satisfy all requirements even in exceptional situations. If an exception occurs, it will be handled internally and not observed by clients.
    Implemented by ensuring that memory allocation never fails, or by defining the insert function's behavior on allocation failure (for example, by having the function return a boolean result indicating whether the insertion took place).
    
Strong guarantee(commit or rollback semantics) either it completely succeeds or it has no effect.
    doing any necessary allocation first, and then swapping buffers if no errors are encountered (the copy-and-swap idiom). In this case, either the insertion of x into v succeeds, or v remains unchanged despite the allocation failure.
    
Basic exception safety:
    no memory is leaked and the object is still in a usable state even though the data might have been modified.
    Implemented by ensuring that the count field is guaranteed to reflect the final size of v. For example, if an error is encountered, the insert function might completely deallocate v and reset its count field to zero. On failure, no resources are leaked, but v's old value is not preserved.

No exception safety: An insertion failure -> corrupted content in v, an incorrect value in the count field, or a resource leak.


Copy and swap
struct String {
  String(String const& other);

  String& operator=(String copy) { // passed by value
    copy.swap(*this); // nothrow swap
    return *this; // old resources now in copy, released in its dtor
  }

  void swap(String& other) throw() {
    using std::swap; // enable ADL, defaulting to std::swap
    swap(data_members, other.data_members);
  }

private:
  Various data_members;
};
void swap(String& a, String& b) { // provide non-member for ADL
  a.swap(b);
}

********************************************************************************
setjmp and longjmp

#include <setjmp.h>
#include <stdio.h>
int proc_4(jmp_buf env, int i)
{
  if (i == 0) longjmp(env, 1);
  return 14 % i;
}
  
int proc_3(jmp_buf env, int i, int j)
{
  return proc_4(env, i) + proc_4(env, j);
}

int proc_2(jmp_buf env, int i, int j, int k)
{
  return proc_3(env, i, k) + proc_3(env, j, k);
}

int proc_1(jmp_buf env, int i, int j, int k, int l)
{
  return proc_2(env, i, j, k+1);
}


main(int argc, char **argv)
{
  jmp_buf env;
  int sj;
  int i, j, k, l;

  if (argc != 5) {
    fprintf(stderr, "usage: sj2 i j k l\n");
    exit(1);
  }

  sj = setjmp(env);
  if (sj != 0) {
    printf("Error -- bad value of i (%d), j (%d), k (%d), l (%d)\n", 
           i, j, k, l);
    exit(0);
  }

  i = atoi(argv[1]);
  j = atoi(argv[2]);
  k = atoi(argv[3]);
  l = atoi(argv[4]);
  
  printf("proc_1(%d, %d, %d, %d) = %d\n", i, j, k, l, proc_1(env, i, j, k, l));
}


#include<iostream.h>
int Div(int x,int y);
void main()
{
	try
	{
		cout<<"5/2="<<Div(5,2)<<endl;
		cout<<"8/0="<<Div(8,0)<<endl;
		cout<<"7/1="<<Div(7,1)<<endl;
	}
	catch(int)
	{
		cout<<"except of deviding zero.\n";
	}
	cout<<"that is ok.\n";
}
int Div(int x,int y)
{
	if(y==0)
		throw y;
	return x/y;
}
