***************************************************************************************************

# Memory:

## Malloc: allocated on the heap 
All threads share a common heap. 
Each thread has a private stack, which it can quickly add and remove items from. This makes stack based memory fast, but if you use too much stack memory, as occurs in infinite recursion,  \
you will get a stack overflow. 

## Dangling pointers
arise when an object is deleted or deallocated, without modifying the value of the pointer, so that the pointer still points to the memory location of the deallocated memory.

***************************************************************************************************

# composition/aggregation
Aggregation differs from ordinary composition in that it does not imply ownership.
In composition, when the owning object is destroyed, so are the contained objects. 
In aggregation, this is not necessarily true. The object may only contain a reference or pointer to the object
Simple rules:
A "owns" B = Composition : B has no meaning or purpose in the system without A
A "uses" B = Aggregation : B exists independently (conceptually) from A
Example 1:
A Company is an aggregation of People. A Company is a composition of Accounts. When a Company ceases to do business its Accounts cease to exist but its People continue to exist.
Example 2: (very simplified)
A Text Editor owns a Buffer (composition). A Text Editor uses a File (aggregation). When the Text Editor is closed, the Buffer is destroyed but the File itself is not destroyed.

***************************************************************************************************
2) encapsulation, polymorphism,inheritance
Encapsulation: A language mechanism for restricting access to some of the object's components

In classical inheritance where objects are defined by classes, classes can inherit attributes and behavior from pre-existing classes called base classes. The resulting classes are known as derived classes.

3）class
a class is a construct that is used to create instances of itself

***************************************************************************************************
# Constructor
## default constructor
a constructor that is automatically generated in the absence of explicit constructors, this automatically provided constructor takes no arguments.
A default constructor is a constructor that either has no parameters, or if it has parameters, all the parameters have default values

# private constructor 
	* A utility class, that only contains static methods. no object instance must ever be created in the program. 
    * Your class is a singleton. This means, not more than one instance of your class exists in the program.
class MyClass
{
private:
  MyClass() { }
  static MyClass* instance;
public:
  MyClass & Instance()
  {
    if(!instance)
        instance = new MyClass();
    return *instance;
  }
};

5) Copy constructor: creating a new object as a copy of an existing object.
The first argument of such a constructor is a reference to an object of the same type as is being constructed
This is the reason of passing a reference to copy constructor. If its not passed by reference then it would pass by value. 
If the argument is passed by value, its copy constructor would call itself to copy the actual parameter to formal parameter. This process would go on until the system runs out of memory

6) 写 operator assignment的时候要注意
Copy constructor copies an existing object to a non existing object, which you are going to create. Assignment operation can happen between two existing objects.
The assignment operator for a class is what allows you to use = to assign one instance to another

The copy assignment operator differs from the copy constructor in that it must clean up the data members of the assignment's target (and correctly handle self-assignment) whereas the copy constructor assigns values to uninitialized data members

Another difference that affects the implementation is that assignment operators have a return value. Returning a reference to the object.

It is one of the special member functions, which means that a default version of it is generated automatically by the compiler if the programmer does not declare one. The default version performs a memberwise copy, where each member is copied by its own copy assignment operator (which may also be programmer-declared or compiler-generated).

7）Can constructor be virtual? why it can or can not? how about destructor.
A virtual call is a mechanism to get work done given partial information. In particular, "virtual" allows us to call a function knowing only any interfaces and not the exact type of the object. To create an object you need complete information. In particular, you need to know the exact type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.

In C++, the constructor cannot be virtual, because when a constructor of a class is executed there is no virtual table in the memory, means no virtual pointer defined yet. So, the constructor should always be non-virtual.


Virtual destructor are useful when you can delete an instance of a derived class through a pointer to base class:
If your derived class destructor is virtual then objects will be destrcuted in a order(firstly derived object then base ). If your derived class destructor is NOT virtual then only base class object will get deleted(because pointer is of base class "Base *myObj"). So there will be memory leak for derived object

Virtual base classes (C++ only)
Suppose you have two derived classes B and C that have a common base class A, and you also have another class D that inherits from B and C. You can declare the base class A as virtual to ensure that B and C share the same subobject of A.

基类构造函数与destructor can't be inheritanced.

构造函数调用顺序：
1. 基类构造函数，调用顺序按照被继承时声明从左到右。
2. 内嵌对象构造函数
3. 派生类构造函数

8) what's the default functions of class
Default constructor: Declared only if no user-defined constructor is declared. Defined when used
Copy constructor - declared only if the user hasn't declared one. Defined if used
The implicit copy constructor does a member-wise copy of the source object.
because the object contains raw pointers and you need to take a "deep" copy of the pointer.
Copy-assignment operator same as above
Destructor same as above
由于类中定义了构造函数，编译系统不会为其生成默认构造函数。由于自定义构造函数带有形参，所以调用时必须给出初始值 。
Constructor and destructor are public. 

9) describe virtual table
The virtual table is a lookup table of functions used to resolve function calls in a dynamic/late binding manner.
every class that uses virtual functions (or is derived from a class that uses virtual functions) is given it’s own virtual table.
A virtual table contains one entry for each virtual function that can be called by objects of the class. Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class.

the compiler also adds a hidden pointer to the base class, which we will call *__vptr
The compiler also adds a hidden pointer to the most base class that uses virtual functions

vtables are structures created at compile time (because they can be determined at compile time). When objects of a particular type are created at runtime they will have a vptr which will be initialized to point at a static vtable at construction time.

10) what's the size of empty class
The C++ standard guarantees that the size of any class is at least one. The C++ standard states that no object shall have the same memory address as another object. There are several good reasons for this.
To guarantee that new will always return a pointer to a distinct memory address.
To avoid some divisions by zero. For instance, pointer arithmetics (many of which done automatically by the compiler) involve dividing by sizeof(T).

13) what's the difference of passing by reference  & passing by value
Passing by reference means the called functions' parameter will be the same as the callers' passed argument 
Pass by value means the called functions' parameter will be a copy of the callers' passed argument. 
Thus changes to a parameter done by the called function in one case changes the argument passed and in the other case just changes the value of the parameter in the called function (which is only a copy)

difference address reference 
you can't pass NULL when passing by reference


14) when is the copy constructor called type cast 调用
explicit keyword
This forces the code to either use a parameter of the correct type, or cast the parameter to the correct type.

Suppose you have a class String:
class String { public: String(int n); // allocate n bytes to the String object String(const char *p); // initializes object with char *p };
Now if you try
String mystring = 'x';
the char 'x' will be implicitly converted to int and then will call the String(int) constructor. But this is not what the user might have intended. So to prevent such conditions, we shall define the constructor as explicit:
class String { public: explicit String (int n); //allocate n bytes String(const char *p); // initialize sobject with string p };


template
Function templates are special functions that can operate with generic types. 
can be adapted to more than one type or class without repeating the entire code for each type.

Class templates are commonly used to implement containers
You can use class templates to create a family of classes that operate on a type. Class templates are parameterized types. They imply that a separate class could be created for each conceivable value of the parameters (known as template arguments) passed in.
Template arguments can be types or constant values of a specified type. For example:

// class_templates.cpp
template <class T, int i> 
class TempClass 
{
public:
    TempClass( void );
    ~TempClass( void );
    int MemberSet( T a, int b );
private:
    T Tarray[i];
    int arraysize;
};

int main()
{
}









17) deep copy & shallow copy
The default copy constructor creates only shallow copies.
A deep copy copies all fields, and makes copies of dynamically allocated memory pointed to by the fields. A deep copy occurs when an object is copied along with the objects to which it refers. Shallow copy is a bit-wise copy of an object.

18) auto pointer
The auto_ptr template class describes an object that stores a pointer to a single allocated object of type Type* that ensures that the object to which it points gets destroyed automatically when control leaves a scope

The direct replacement for auto_ptr (or the closest thing to one anyway) is unique_ptr. As far as the "problem" goes, it's pretty simple: auto_ptr transfers ownership when it's assigned. unique_ptr also transfers ownership, but thanks to codification of move semantics and the magic of rvalue references, it can do so considerably more naturally. 

When using unique_ptr, there can be at most one unique_ptr pointing at any one resource. 
shared_ptr, on the other hand, allows for multiple pointers to point at a given resource

19) what's the difference of new & malloc
Should be used because it calls the constructor/destructor

20) what happens when new/malloc fails
std::bad_alloc

21) what's the abstract class
An abstract class is a class that is designed to be specifically used as a base class; 
An abstract class contains at least one pure virtual function.

22) what's the pure virtual function?
virtual functions we have written have a body (a definition)
pure virtual function (or abstract function) that has no body at all, only the declaration
to be redefined by derived classes.
simply assign the function the value 0.

First, any class with one or more pure virtual functions becomes an abstract base class, which means that it can not be instantiated
Second, any derived class must define a body for this function, or that derived class will be considered an abstract base class as well.
An interface class is a class that has no members variables, and where all of the functions are pure virtual
the class is purely a definition, and has no actual implementation.
Interfaces are useful when you want to define the functionality that derived classes must implement, but leave the details of how the derived class implements that functionality entirely up to the derived class.

23) how to print "hello world" before main()
global object, print hello in the constructor 

24) inheritance 哪些能继承，哪些不能

25）class a array[50],怎么给这50个元素置初值，不能循环赋值，就是这个意思，你可以动态分配

26）static
C:
A static variable inside a function keeps its value between invocations.
A static global variable or a function is "seen" only in the file it's declared in
C++:
静态数据成员是私有类型，可以直接初始化，之后就不允许直接访问。
A static member function differs from a regular member function in that it can be called without an instance of a class, and since it has no instance, it cannot access non-static members of the class. 



In software engineering, coupling or dependency is the degree to which each program module relies on each one of the other modules.
Disadvantage
1. A change in one module usually forces a ripple effect of changes in other modules. 
2. Assembly of modules might require more effort and/or time due to the increased inter-module dependency. 
3. A particular module might be harder to reuse and/or test because dependent modules must be included. 


What is Object?
Software objects are conceptually similar to real-world objects: they too consist of state and related behavior. An object stores its state in fields (variables in some programming languages) and exposes its behavior through methods (functions in some programming languages). Methods operate on an object's internal state and serve as the primary mechanism for object-to-object communication. Hiding internal state and requiring all interaction to be performed through an object's methods is known as data encapsulation — a fundamental principle of object-oriented programming.

Bundling code into individual software objects provides a number of benefits, including:

Modularity: The source code for an object can be written and maintained independently of the source code for other objects. Once created, an object can be easily passed around inside the system.
Information-hiding: By interacting only with an object's methods, the details of its internal implementation remain hidden from the outside world.
Code re-use: If an object already exists (perhaps written by another software developer), you can use that object in your program. This allows specialists to implement/test/debug complex, task-specific objects, which you can then trust to run in your own code.
Pluggability and debugging ease: If a particular object turns out to be problematic, you can simply remove it from your application and plug in a different object as its replacement. This is analogous to fixing mechanical problems in the real world. If a bolt breaks, you replace it, not the entire machine.



2.    What is Polymorphism? How to implement polymorphism?
The name "polymorphism" means that something has many (poly), forms (morph).
In programming languages, polymorphism means that some code or operations or objects behave differently in different contexts.
Method overloading refers to methods that have the same name but different signatures inside the same class. Method overriding is where a subclass replaces the implementation of one or more of its parent's methods.

3.    What is Dynamic Binding and Static Binding?
Dynamic Binding refers to the case where compiler is not able to resolve the call and the binding is done at runtime only.
If the compiler can resolve the binding at the compile time only then such a binding is called Static Binding or Early Binding.

4.    What is OOP?
Object-oriented programming (OOP) is a programming paradigm using "objects" – data structures consisting of data fields and methods together with their interactions – to design applications and computer programs.



5.    What are important features of OOP? Why OOP are better?
Inheritance, polymorphism, encapsulation, data abstraction, messaging, modularity

6.    What is Class?

7.    Difference between class and object.
A class is a template for objects. 
An object is a member or an "instance" of a class.  

8.    What is enum? What is enum's limitation?
constant

9.    What are interface and abstract class?
An interface class is a class that has no members variables, and where all of the functions are pure virtual
Abstract class is a class that can not be instantiated. 
 abstract classes are incomplete, it may contain only definition of the properties or methods and derived classes that inherit this implements it's properties or methods. 

10.    How would you choose between an abstract class and interface?
Interfaces can't have any concrete implementations. Abstract base classes can. 

11.    What are struct and union?
A structure contains an ordered group of data objects. Unlike the elements of an array, the data objects within a structure can have varied data types. Each data object in a structure is a member or field.
A union is an object similar to a structure except that all of its members start at the same location in memory. A union variable can represent the value of only one of its members at a time.

12.    What is the difference between a struct and a class in C++?
that members of a class are private by default, whereas members of a struct are public by default. Inheritance between classes is also private by default, and inheritance between structs is public by default. 

13.    Can struct be derived from Class? Yes;

14.    What is a constructor, destructor, default constructor, copy constructor?
subroutine called to create an object.
a method which is automatically invoked when the object is destroyed. Its main purpose is to free the resources


A default constructor is a constructor that either has no parameters, or if it has parameters, all the parameters have default values.
The compiler will implicitly define A::A() when the compiler uses this constructor to create an object of type A. The constructor will have no constructor initializer and a null body.
A copy constructor is a special constructor in the C++ programming language for creating a new object as a copy of an existing object.
The first argument of such a constructor is a reference to an object of the same type as is being constructed 

Whenever you pass an object by value, you implicitly invoke its copy constructor, because the object passed is a copy of the original argument. The result is an infinite recursion: the copy constructor calls another copy constructor, which in turn calls another copy constructor and so on. To avoid this infinite recursion, C++ requires that a copy constructor's parameter be passed by reference. 

15.    What is the purpose of a constructor/destructor?

16.    What is the meaning of the “explicit” keyword for constructors?
Prevents implicit type conversions, which might cause errors. 
To tell the compiler that a certain constructor may not be used to implicitly cast an expression to its class type. 

17.    How to disable the default functions (like default constructor, default destructor …) in a class?
Overload it


18.    What is (default) copy constructor? When should a custom copy constructor be defined for a class and why?
Outside resource. Shallow copy

19.    What are differences between copy constructor and assignment?
A a(b);
A a = b;
A c;
c=d;
A copy constructor is used to initialize a previously uninitialized object from some other object's data. An assignment operator is used to replace the data of a previously initialized object with some other object's data.

20.    What is Friend?
A friend of a class X is a function or class that is not a member of X, but is granted the same access to X as the members of X. 
友元关系不能传递，单向的，不被继承。

21.    What is inheritance?
22.    How many inheritance mechanisms?
Inheritance is a mechanism of reusing and extending existing classes without modifying them, thus producing hierarchical relationships between them.

23.    What is virtual inheritance?
Class Base{
};
Class A: public virtual Base{
};

Virtual base classes, used in virtual inheritance, is a way of preventing multiple "instances" of a given class appearing in an inheritance hierarchy when using multiple inheritance.
Avoid diamond inheritance

24.    What is a virtual memory, why do we use? Advantage? 
In computing, virtual memory is a memory management technique developed for multitasking kernels. This technique virtualizes the main storage available to a process or task, as a contiguous address space which is unique to each running process, or virtualizes the main storage available to all processes or tasks on the system as a contiguous global address space


25.    What is virtual function? What are the consequences of using a virtual method?
class a{
public:
	virtual int foo(){}
};
A virtual method in a parent allows children to have a different implementation for it. A pure virtual method in a parent forces children to have an implementation for it (interface in Java). A class with a pure virtual method is called virtual. 

In OOP when a derived class inherits from a base class, an object of the derived class may be referred to via a pointer or reference of either the base class type or the derived class type. If there are base class methods overridden by the derived class, the method actually called by such a reference or pointer can be bound either 'early' (by the compiler), according to the declared type of the pointer or reference, or 'late' (i.e. by the runtime system of the language), according to the actual type of the object referred to.
Virtual functions are resolved 'late'. If the function in question is 'virtual' in the base class, the most-derived class's implementation of the function is called according to the actual type of the object referred to, regardless of the declared type of the pointer or reference. If it is not 'virtual', the method is resolved 'early' and the function called is selected according to the declared type of the pointer or reference.


26.    What is Virtual Base Class?
When two or more objects are derived from a common base class, we can prevent multiple copies of the base class being present in an object derived from those objects by declaring the base class as virtual when it is being inherited. Such a base class is known as virtual base class. This can be achieved by preceding the base class’ name with the word virtual. 

27.    What is virtual destructor?
Class a{
   virtual ~a(){}
};
Class b: public a{
}
a *p = new b();
delete p;
Virtual destructors are useful when you can delete an instance of a derived class through a pointer to base class:

28.    What is inline function?
an inline function is a function upon which the compiler has been requested to perform inline expansion.
replaces a function call site with the body of the callee

29.    What is function object?
allowing an object to be invoked or called as if it were an ordinary function


class Functor
{
public:
    int operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    Functor f;
    int a = 5;
    int b = 7;
    int ans = f(a, b);
}

30.    What is Function Adaptor?
A function adaptor is an instance of a class that adapts a global or member function so that the function can be used as a function object.
重载 operator()



31.    What is Function and Operator overloading?
a specific case of polymorphism, 
where different operators have different implementations depending on their arguments. 

32.    What is new and delete?

33.    What's memory leak?
A memory leak, in computer science (or leakage, in this context), occurs when a computer program consumes memory but is unable to release it back to the operating system.
In object-oriented programming, a memory leak happens when an object is stored in memory but cannot be accessed by the running code

34.    What's memory overflow?and stack overflow and heap overflow
A memory overflow is really just a form of a buffer overflow.  The impact of memory overflow is unexpected behavior or program failure.

A program, while writing data to a buffer, overruns the buffer's boundary and overwrites adjacent memory.

In software, a stack overflow occurs when too much memory is used on the call stack.
 两种情况:
Very deep or infinite recursion。Very large stack variables。
A heap overflow is a type of buffer overflow。


35.    How to detect memory leak and how to resolve it?

36.    How to allocate memory in C?

37.    Where are function local variables stored at?    stack
Where are static variables stored at?

38.    What are call by value and call by reference? What are their differences?
Call by value: In the call by value method, the called function creates a new set of variables and copies the values of the arguments into them.
Call by reference: In the call by reference method, instead of passing values to the function being called, references/pointers to the original variables are passed.

39.    What is variable scope?
a scope is the context within a computer program in which a variable name or other identifier is valid and can be used, or within which a declaration has effect.

40.    What is extern variable? How are these variables resolved (at what stage: Compile /Link/ Run)?
A variable must be defined once in one of the modules of the program. If there is no definition or more than one, an error is produced, possibly in the linking stage. 

41.    What is storage draft?
 
42.    What are multi-cast, broadcast, unicast?
Unicast is the term used to describe communication where a piece of information is sent from one point to another point.
Broadcast is the term used to describe communication where a piece of information is sent from one point to all other points. 
Multicast is the term used to describe communication where a piece of information is sent from one or more points to a set of other points

43.    What is io multi plex?

44.    What are pointer and reference? 
1. A pointer can be re-assigned any number of times while a reference can not be reassigned after initialization. 
2. A pointer can point to NULL while reference can never point to NULL 
3. You can't take the address of a reference like you can with pointers 
4. There's no "reference arithmetics" (but you can take the address of an object pointed by a reference and do pointer arithmetics on it as in &obj + 5). 

45.    When would you use a pointer/reference?

46.    What is purpose of pointer to pointers?

47.    Can we use a base pointer to access the derived class?

48.    What's the pointer of inheritance?

49.    size of a pointer.
不同的机器不同

50.    Explain pass by value, pointer, reference

51.    Differences between pointer and reference?

52.    What are function pointer, pointer to function and pointer to member?

53.    What are this pointer and smart pointer?
a smart pointer is an abstract data type that simulates a pointer while providing additional features, such as automatic garbage collection or bounds checking.

54.    What are static variable and static member functions?
When we instantiate a class object, each object gets it’s own copy of all normal member variables.
Member variables of a class can be made static by using the static keyword. Static member variables only exist once in a program regardless of how many class objects are defined
static variables inside classes? One great example is to assign a unique ID to every instance of the class. 

Like static member variables, static member functions are not attached to any particular object.
Because static member functions are not attached to a particular object, they can be called directly by using the class name and the scope operator.

First, because static member functions are not attached to an object, they have no this pointer
Second, static member functions can only access static member variables

55.    What is difference between static variable and global variable?

Scope and lifetime

Regarding what they are: the two different types of variables have different visibility scopes. 
A static variable will only be visible (that is, accessible) inside the function it is defined. Globals exists on a global level; that is, that can be accessed anywhere.

全局变量和静态变量的区别： 全局变量在整个工程文件内都有效；静态全局变量只在定义它的文件内有效；静态局部变量只在定义它的函数内有效，只是程序仅分配一次内存，函数返回后，该变量不会消失；

56.    Where is the static variable stored? Why is static?
bss is used by many compilers and linkers for a part of the data segment containing statically-allocated variables represented solely by zero-valued bits initially (i.e., when execution begins). It is often referred to as the "bss section" or "bss segment"

57.    Differences between a static member function and non-static member functions.
static variables keep their values and are not destroyed even after they go out of scope
C++ introduces two new uses for the static keyword when applied to classes: static member variables, and static member classes. 
Static member variables only exist once in a program regardless of how many class objects are defined. One way to think about it is that all objects of a class share the static variables. 
Static variables does not belong to any object. exists even if there are no objects of the class have been instantiated! 
Can accessed directly using the class name and the scope operator:

Like static member variables, static member functions are not attached to any particular object

1. static member functions are not attached to an object, they have no this pointer! 
2. static member functions can only access static member variables.

The scope resolution operator helps to identify and specify the context to which an identifier refers. 

58.    What are differences between static variable and local variable in a function?

59.    Advantages of using static members rather than globals?
Globals can be accessed anywhere.

60.    What does it mean to declare a member function as virtual/static?

61.    What is virtual function? Why virtual functions? How to implement
A virtual function is a member function that you expect to be redefined in derived classes. 
call a derived class's function by using a point to the base class

62.    What is virtual destructor? Why virtual destructor?
Virtual destructors are useful when you can delete an instance of a derived class through a pointer to base class:


63.    What is Pure Virtual Function and how to implement Pure Virtual Function?
Virtual int a()=0;
a virtual function that is required to be implemented by a derived class
A class that contains at least one pure virtual function is considered an abstract class.


64.    What is exception handling?
To catch exceptions we must place a portion of code under exception inspection. This is done by enclosing that portion of code in a try block. 
An exception is thrown by using the throw keyword from inside the try block
When an exceptional circumstance arises within that block, an exception is thrown that transfers the control to the exception handler. 
If no exception is thrown, the code continues normally and all handlers are ignored.

When an exception is raised (using throw), execution of the program immediately jumps to the nearest enclosing try block (propagating up the stack if necessary). If any of the catch handlers attached to the try block handle that type of exception, that handler is executed and the exception is considered handled.
If no appropriate catch handlers exist, execution of the program propagates to the next enclosing try block. If no appropriate catch handlers can be found before the end of the program, the program will fail with an exception error.

Exception thrown from destructor:
bad because it causes the application to leak memory. 
When an object is deleted, two things happen: first the destructor is called and second the delete operator is called. It is the delete operator that actually releases the storage. 
If the destructor throws an exception the delete operator is never called so you will leak memory. 

Throwing an exception out of a destructor is dangerous.
If another exception is already propagating the application will terminate.

65.    How to call C function from C++? 
extern "C" void foo( ); 

66.    How to use a function in C++ from a C function?

67.    What are differences between method overloading and method overriding?
Method overloading is defining several methods in the same class, that accept different numbers and types of parameters.
Overriding means you implement a method in the subclass that has the same signature as one in the parent class.


68.    What is pthread_mutex?
A mutex is a MUTual EXclusion device, and is useful for protecting shared data structures from concurrent modifications, and implementing critical sections and monitors. 

69.    What are data structures?

70.    What are Traversals in tree?

71.    What are Hash tables?

72.    What are Trees and B+ trees?

73.    How to serialize and deserialize 1) a binary tree and 2) a binary graph?


74.    What’s the difference between tree and graph?
Trees have direction (parent / child relationships) and don't contain cycles.


75.    What is const object?
If a class is not initialized using a parameterized constructor, a public default constructor must be provided — if no public default constructor is provided in this case, a compiler error will occur.

Once a const class object has been initialized via constructor, any attempt to modify the member variables of the object is disallowed, as it would violate the constness of the object.

76.    What is const member function?
Any const member function that attempts to change a member variable or call a non-const member function will cause a compiler error to occur. 
有const函数与没const函数是overloading。
对const 成员变量赋值只能通过构造函数。常成员函数不能更新对象的数据成员，也不能调用该类中没有用const修饰的成员函数。如果将一个对象说明为常对象，则通过该常对象只能调用它的常成员函数，而不能调用其他成员函数。
class a{
public:
   int foo() const {}
};

const int * ptr1;       /* A pointer to a constant integer:
                             the value pointed to cannot be changed  */
int * const ptr2;       /* A constant pointer to integer:
                             the integer can be changed, but ptr2
                             cannot point to anything else           */
const int * const ptr3; /* A constant pointer to a constant integer:
                             neither the value pointed to
                             nor the pointer itself can be changed   */
const对左边的声明起作用。

const Member Functions
Declaring a member function const means that the this pointer is a pointer to a const object. Data members of the class will be const within that function. The function is still able to change the value, but requires a const_cast to do so:
void foo::p() const{
   member = 1;                       // illegal
   const_cast <int&> (member) = 1;   // a bad practice but legal
}
This keyword mutable  can only be applied to non-static and non-const data members of a class. If a data member is declared mutable, then it is legal to assign a value to this data member from a const member function.


77.    What is const pointer?
A non-const pointer can be redirected to point to other addresses. 
A const pointer always points to the same address, and this address can not be changed. 
A pointer to a non-const value can change the value it is pointing to. 
A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to. 


78.    What are STL and Generic Algorithm?

79.    What are stack, stash and queue?

80.    What is Container?

81.    What is Iterator?
In C++, an iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements of that range using a set of operators (at least, the increment (++) and dereference (*) operators).


82.    What is string?

83.    What is sequential container?
elements can be accessed sequentially

84.    What are vector, list, deque and their differences?
double-ended queue. 

85.    What is associative container?


86.    What are map, set, multimap, and multiset?
Map: binary search tree, hash table:  associative container
set: binary search trees. 
Sets are containers that store unique elements following a specific order.
In a set, the value of an element also identifies it (the value is itself the key, of type T), and each value must be unique. The value of the elements in a set cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

Set elements cannot be modified while they are in the set.
With map<key_class,value_class>, you can modify the value_class in-place, assuming you have a non-const reference to the map.




87.    What is the advantage to use map instead of list? 
Binary search tree

88.    In what way is a std::vector more efficient than a std::set?
 

89.    When is it more efficient to use a sorted vector instead of a set for storing ordered objects? 
Access O(1) vs O(lgn)

90.    What is the difference between vector and list? 

91.    What is the cost when delete an element from a vector and list? 


92.    How to iterator through a vector, list and map? What is the difference? 


93.    In order to optimize for insert/lookup, use a map or a hash map?

map uses a red-black tree as the data structure, so the elements you put in there are sorted, and insert/delete is O(log(n)). The elements need to implement at least operator<.
hashmap uses a hash, so elements are unsorted, insert/delete is O(1). Elements need to implement at least operator== and you need a hash function.
The STL includes the ordered and the unordered map (std::map and std::unordered_map) containers. In an ordered map the elements are sorted by the key, insert and access is in O(log n)). Usually the STL internally uses red black trees for ordered maps. But this is just an implementation detail. In an unordered map insert and access is in O(1). It is just another name for a hashtable.


94.    What is Template?

95.    What is function template?
Function templates are special functions that can operate with generic types.
Template<class T>
int a(T in){
}

96.    What is class template?
A class template provides a specification for generating classes based on parameters. Class templates are commonly used to implement containers. 
A class template is instantiated by passing a given set of types to it as template arguments.
The C++ Standard Library contains many class templates, in particular the containers adapted from the Standard Template Library, such as vector.


97.    What are thread and multi-thread?
98.    What are differences between thread and process? 
Both processes and threads are independent sequences of execution. The typical difference is that threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.

99.    Advantage of thread over process?
An advantage of using multiple threads over using separate processes is that the former share a single address space, all open files, and other resources.

Performance

Threads improve the performance (throughput, computational speed, responsiveness, or some combination of these) of a program. Multiple threads are useful in a multiprocessor system where threads run concurrently on separate processors.


100.    What is difference between constant and preprocessor?
Preprocessor directives are lines included in the code of our programs that are not program statements but directives for the preprocessor. These lines are always preceded by a hash sign (#).

#define identifier replacement




101.    What is difference between define and preprocessor?
#include, #if, #ifdef, #ifndef, #else, #elif, #endif, #define, #undef, #line, #error, and #pragma are all preprocessing directives.



102.    What is syntax of malloc and new keywords 



103.    What is difference between multithreading and multitasking?


104.    What is thread and task? What’s difference between thread and process?
Both processes and threads are independent sequences of execution. The typical difference is that threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.
The major difference between threads and processes is:
Threads share the address space of the process that created it; processes have their own address space. 
Threads have direct access to the data segment of its process; processes have their own copy of the data segment of the parent process. 
Threads can directly communicate with other threads of its process; processes must use interprocess communication to communicate with sibling processes. 
Threads have almost no overhead; processes have considerable overhead. 
New threads are easily created; new processes require duplication of the parent process. 
Threads can exercise considerable control over threads of the same process; processes can only exercise control over child processes. 
Changes to the main thread (cancellation, priority change, etc.) may affect the behavior of the other threads of the process; changes to the parent process does not affect child processes. 

105.    What is the malloc and new, what is the difference between free and delete?


106.    How to create 2 dimensional array using malloc?



107.    What is the most fast sorting algorithm? What is the worst case of it?

108.    What are differences between #define and enum?
enum defines a syntactical element.
#define is a pre-preprocessor directive, executed before the compiler sees the code, and therefore is not a language element of C itself.
Generally enums are preferred as they are type-safe and more easily discoverable. Defines are harder to locate and can have complex behavior, for example one piece of code can redefine a #define made by another. This can be hard to track down.

109.    Differences between inline functions and #define?
Inline functions are parsed by the compiler, 
whereas macros are expanded by the C++ preprocessor.
The difference between an inline function and a regular function is that wherever the compiler finds a call to an inline function, it writes a copy of the compiled function definition.


dynamic_cast can be used only with pointers and references to objects. Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.
dynamic_cast performs a special checking during runtime to ensure that the expression yields a valid complete object of the requested class:
a compilation error since base-to-derived conversions are not allowed with dynamic_cast unless the base class is polymorphic.



static_cast can perform conversions between pointers to related classes, not only from the derived class to its base, but also from a base class to its derived
no safety check is performed during runtime to check if the object being converted is in fact a full object of the destination type

reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other

What is Memory Alignment?
 
Most CPUs require that objects and variables reside at particular offsets in the system's memory. For example, 32-bit processors require a 4-byte integer to reside at a memory address that is evenly divisible by 4. This requirement is called "memory alignment". Thus, a 4-byte int can be located at memory address 0x2000 or 0x2004, but not at 0x2001. On most Unix systems, an attempt to use misaligned data results in a bus error, which terminates the program altogether. On Intel processors, the use of misaligned data is supported but at a substantial performance penalty. Therefore, most compilers automatically align data variables according to their type and the particular processor being used. This is why the size that structs and classes occupy is often larger than the sum of their members' size:

struct Employee
{
int ID;
char state[3]; //CA, NY etc. + terminating null
int salary;
};
Apparently, Employee should occupy 11 bytes (4+3+4). However, most compilers add an unused padding byte after the field 'state' so that it aligns on a 4 byte boundary. Consequently, Employee occupies 12 bytes rather than 11. You can examine the actual size of an aggregate by using the expression sizeof(Employee).



difference between tcp and ip?
1. TCP is a core operating on a relatively high level; IP operates at a lower level.
2. TCP provides communication services at an intermediate level between an application program and the IP; IP encapsulates all data, and is connectionless.
SQL

What is the difference between INNER JOIN and OUTER JOIN?
An inner join of A and B gives the result of A intersect B
An outer join of A and B gives the results of A union B
Left outer join: A left outer join will give all rows in A, plus any common rows in B.


SQL injection
This is done by including portions of SQL statements in an entry field in an attempt to get the website to pass a newly formed rogue SQL command to the database


index
Indexes allow the database application to find data fast; without reading the whole table. 
Indexes slow down inserts and updates (which can become a really serious issue with locking) and cost disk space. 

The advantages of indexes are as follows:
Their use in queries usually results in much better performance. 
They make it possible to quickly retrieve (fetch) data. 
They can be used for sorting. A post-fetch-sort operation can be eliminated. 
Unique indexes guarantee uniquely identifiable records in the database. 
The disadvantages of indexes are as follows:
They decrease performance on inserts, updates, and deletes. 
They take up space (this increases with the number of fields used and the length of the fields). 
Some databases will monocase values in fields that are indexed. 
Database normalization is the process of organizing the fields and tables of a relational database to minimize redundancy and dependency. Normalization usually involves dividing large tables into smaller (and less redundant) tables and defining relationships between them.


primary key, unique key
Primary keys and unique keys are similar. A primary key is a column, or a combination of columns, that can uniquely identify a row. It is a special case of unique key. 
A table can have at most one primary key, but more than one unique key.

Singleton
class MyClass()
{
private:
  MyClass() { }
  static MyClass* instance;
public:
  MyClass & Instance()
  {
    if(!instance)
        instance = new MyClass();
    return instance;
  }
};

Simple factory pattern
describes a class that has one creation method with a large conditional that based on method parameters chooses which product class to instantiate and then return.
class UserFactory {
	public static function create($type) {
    	switch ($type) {
        	case 'user': return new User();
        	case 'customer': return new Customer();
        	case 'admin': return new Admin();
        	default:
            	throw new Exception('Wrong user type passed.');
    	}
	}
}

Factory Method pattern: 
Define an interface, then sub class does implementation.

Abstract Factory pattern:
used to create a family/group of individual factories. 
Car + CombustionEngine + SteeringWheel
Plane + JetEngine + Yoke


Builder:
Create a delegate/callback Builder. 
Class calls this delegate to do the creation. Also the class can have many delegates.
Disadvantage: Should have one builder for each type of product.




class size
Size of all non-static data members
Order of data members
Byte alignment or byte padding
Size of its immediate base class
The existence of virtual function(s) (Dynamic polymorphism using virtual functions).
Compiler being used
Mode of inheritance (virtual inheritance)

***************************************************************************************************************
virtual table: contains an entry for each virtual function
entries in the vtable can point to most derived functions
vtables exist at the class level, meaning one vtable per class, and is shared by all instances.

steps:
    vpointer find vtable
    vtable[function name] find correct function address
      
    Get the vtable pointer, which points to an array of function pointers (function addresses), one for each virtual function, from the object.
    Get the right function address from the vtable into a register (the index where the correct function address is stored is decided at compile-time).
    Jump to the address in that register, rather than jumping to a hardcoded address.

slow:
    compiler can't know which function to call, can't inline it or perform optimization (preparing registers, calling, restoring state afterwards).
    cache and branch predictor can't help. no perfectly predictable branch. 

function call steps:
    Copy some registers on the stack, to allow the called function to use those registers.
    Copy the arguments into predefined locations, so that the called function can find them regardless from where it is called.
    Push the return address.
    Branch/jump to the function's code, which is a compile-time address and hence hardcoded in the binary by the compiler/linker.
    Get the return value from a predefined location and restore registers we want to use.

Virtual Destructor: used to free the memory of the derived class object, by using the base class's pointer object

No virtual destructor for base class: 
    Deleting an object of a derived class using a pointer of the parent class shows an undefined behavior

Implementation
When the compiler generates the code for the destructor, it adds extra code both before and after the user defined code. 

    modify vptr to refer to the vtable of derived
    user code
    calls to the member destructors and base destructor(s) this->~mybase()

`delete`ing base classes with non-virtual destructors
    undefined 

https://stackoverflow.com/questions/32132058/what-do-clang-and-gcc-do-when-deleteing-base-classes-with-non-virtual-destruct/37738132#37738132

Take that address of that first base class object, do roughly the equivalent of a reinterpret_cast on it, and try to use that memory as if it were an object of the base class specified by the pointer (e.g., base2). For example, let's assume base2 has a pointer at offset 14, and base2's destructor attempts to delete a block of memory it points at. With a non-virtual destructor, it'll probably receive a pointer to the base1 subject--but it'll still look at offset 14 from there, and try to treat that as a pointer, and pass it to delete. It could be that base1 contains a pointer at that offset, and it's actually pointing at some dynamically allocated memory, in which case this might actually appear to succeed. Then again, it could also be that it's something entirely different, and the program dies with an error message about (for example) attempting to free an invalid pointer.

    #include <iostream>
    #include <string>
    #include <vector>
    
    class base{ 
        char *data;
        std::string s;
        std::vector<int> v;
    public:
        base() { data = new char;  v.push_back(1); s.push_back('a'); }
        ~base() { std::cout << "~base\n"; delete data; }
    };
    
    class base2 {
        char *data2;
    public:
        base2() : data2(new char) {}
        ~base2() { std::cout << "~base2\n"; delete data2; }
    };
    
    class derived : public base, public base2 { 
        char *more_data;
    
    public:
        derived() : more_data(new char) {}
        ~derived() { std::cout << "~derived\n"; delete more_data; }
    };
    
    int main() {
        base2 *b = new derived;
        delete b;
    }

***************************************************************************************************************
stack unwinding:
  When a scope is exited everything within that scope is destroyed: destroying local objects and calling destructors
    
RAII(Resource acquisition is initialization): Scope-Bound Resource Management
    encapsulate a resource into a class (whose constructor usually - but not necessarily** - acquires the resource, and its destructor always releases it)
    use the resource via a local instance of the class*
    the resource is automatically freed when the object gets out of scope

Benefit:
encapsulation: resource management logic is defined in the class, not at each call site
exception safety: if an exception is thrown, destructors will be called 

Limitation:
RAII only works for resources acquired and released (directly or indirectly) by stack-allocated objects

RawResourceHandle* handle=createNewResource();
handle->performInvalidOperation();  // Oops, throws exception
...
deleteResource(handle); // oh dear, never gets called so the resource leaks



class ManagedResourceHandle {
public:
   ManagedResourceHandle(RawResourceHandle* rawHandle_) : rawHandle(rawHandle_) {};
   ~ManagedResourceHandle() {delete rawHandle; }
   ... // omitted operator*, etc
private:
   RawResourceHandle* rawHandle;
};

ManagedResourceHandle handle(createNewResource());
handle->performInvalidOperation();
***************************************************************************************************************
volatile: ask the compiler not to optimization for this variable
optimization (of some parts of your program) may be undesirable, because it may be that someone else is changing the value of some_int from outside the program which compiler is not aware of

    



vector initialization
class broad
{
    public:
        broad(int m, int n)
        : m(m, vector<int>(n, 1))
        {
            
        }

    private:
        vector<vector<int>> m;
    
};


int main()
{
    int a=5, b=0;
    int &r = a;
    r = b++;
    cout<<a<<r<<b;   //001

    return 0;
}

     struct A{
         ~A()
         {
             cout<< "~A";
         }
     };
     
     struct B: public A
     {
         virtual ~B()
         {
             cout<< "~B";
         }
     };
     
int main()
{


    A*a = new B();    // ~A
    delete a;
    return 0;
}

     struct A{
         virtual void print(int x = 1)
         {
             cout<< "A" << x;
         }
     };
     
     struct B: public A
     {
          virtual void print(int x = 2)
         {
             cout<< "B" << x;
         }
     };
     
int main()
{
    A*a = new B;
    a->print();
    return 0;
}

******************************************************************
Virtual inheritance
ensures only one copy of a base class's member variables are inherited by grandchild derived classes.
most useful for multiple inheritance
struct Animal {
    virtual ~Animal() = default;
    virtual void Eat() {}
};

// Two classes virtually inheriting Animal:
struct Mammal: virtual public Animal {
    virtual void Breathe() {}
};

struct WingedAnimal: virtual public Animal {
    virtual void Flap() {}
};

// A bat is still a winged mammal
struct Bat: Mammal, WingedAnimal {};

******************************************************************

What are pointer and reference? 
1. A pointer can be re-assigned any number of times while a reference can not be reassigned after initialization. 
Once defined, a reference cannot be reassigned because it is an alias to its target.
2. A pointer can point to NULL while reference can never point to NULL 
3. You can't take the address of a reference like you can with pointers. 
That is because a reference is not an object, it is an alias (this means it is another name for an object).
4. There's no "reference arithmetics" (but you can take the address of an object pointed by a reference and do pointer arithmetics on it as in &obj + 5). 

Give an example of when you must use a reference instead of a pointer?
Copy constructor


The difference between vector and deque(Double-ended queues)
One main difference between vectors and deques is that the latter allows efficient insertion at the front of the structure as well as the back.
Deques also do not guarantee that their elements are contiguous in memory so the at-style operator (indexing) may not be as efficient.

A deque is somewhat recursively defined: internally it maintains a double-ended queue of chunks (“blocks” in the graphic below) of fixed size. Each chunk is a vector, and the queue (“map” in the graphic below) of chunks itself is also a vector.


placement new
The simplest use is to place an object at a particular location in memory. This is done by supplying the place as a pointer parameter to the new part of a new expression
void someCode()
{
  char memory[sizeof(Fred)];     // Line #1
  void* place = memory;          // Line #2

  Fred* f = new(place) Fred();   // Line #3 (see "DANGER" below)
  // The pointers f and place will be equal

  ...
}

Order of Constructor/ Destructor Call in C++
 base class is called first to initialize all the inherited members.



lvalue, rvalue
An lvalue refers to an object that persists beyond a single expression. You can think of an lvalue as an object that has a name.
An rvalue is a temporary value that does not persist beyond the expression that uses it.
int x = 3 + 4;
In this example, x is an lvalue because it persists beyond the expression that defines it. The expression 3 + 4 is an rvalue because it evaluates to a temporary value that does not persist beyond the expression that defines it.

Unique pointer
A unique_ptr does not share its pointer. It cannot be copied to another unique_ptr, passed by value to a function, or used in any C++ Standard Library algorithm that requires copies to be made.
  std::unique_ptr<int> u3 (new int);

  The shared_ptr type is a smart pointer in the C++ standard library that is designed for scenarios in which more than one owner might have to manage the lifetime of the object in memory. After you initialize a shared_ptr you can copy it, pass it by value in function arguments, and assign it to other shared_ptr instances. All the instances point to the same object


Stack unwinding:
As you create objects statically (on the stack as opposed to allocating them in the heap memory) and perform function calls, they are "stacked up".

When a scope (anything delimited by { and }) is exited (by using return XXX;, reaching the end of the scope or throwing an exception) everything within that scope is destroyed (destructors are called for everything). This process of destroying local objects and calling destructors is called stack unwinding.

avoiding memory leaks (anything dynamically allocated that is not managed by a local object and cleaned up in the destructor will be leaked) 
the C++ specifications state that you should never throw an exception before any existing exception has been handled. This means that the stack unwinding process should never throw an exception


Exception safety guarantees, guidelines that class library implementers and clients can use when reasoning about exception handling safety in any programming language that uses exceptions, particularly C++.
no-leak guarantee



Memory management
static variable: 



The OFFSETOF() macro
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

#include <stdio.h>
 
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
 
typedef struct PodTag
{
   int     i;
   double  d;
   char    c;
} PodType;
 
int main()
{
   printf("%d", OFFSETOF(PodType, c) );
    virtual table: contains an entry for each virtual function
entries in the vtable can point to most derived functions
vtables exist at the class level, meaning one vtable per class, and is shared by all instances.

steps:
    vpointer find vtable
    vtable[function name] find correct function address
      
    Get the vtable pointer, which points to an array of function pointers (function addresses), one for each virtual function, from the object.
    Get the right function address from the vtable into a register (the index where the correct function address is stored is decided at compile-time).
    Jump to the address in that register, rather than jumping to a hardcoded address.


slow:
    compiler can't know which function to call, can't inline it or perform optimization (preparing registers, calling, restoring state afterwards).
    cache and branch predictor can't help. no perfectly predictable branch. 


function call steps:
    Copy some registers on the stack, to allow the called function to use those registers.
    Copy the arguments into predefined locations, so that the called function can find them regardless from where it is called.
    Push the return address.
    Branch/jump to the function's code, which is a compile-time address and hence hardcoded in the binary by the compiler/linker.
    Get the return value from a predefined location and restore registers we want to use.




Virtual Destructor: used to free the memory of the derived class object, by using the base class's pointer object

No virtual destructor for base class: 
    Deleting an object of a derived class using a pointer of the parent class shows an undefined behavior

Implementation
When the compiler generates the code for the destructor, it adds extra code both before and after the user defined code. 

    modify vptr to refer to the vtable of derived
    user code
    calls to the member destructors and base destructor(s) this->~mybase()
    


   getchar();
   return 0;
}

((size_t)&(((PodType *)0)->c))
Since we are considering 0 as address of the structure variable, c will be placed after 16 bytes of its base address i.e. 0x00 + 0x10. Applying & on the structure element (in this case it is c) returns the address of the element which is 0x10. Casting the address to unsigned int (size_t) results in number of bytes the element is placed in the structure.


aligned malloc implementation

void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void* p1; // original block
    void** p2; // aligned block
    int offset = alignment - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
       return NULL;
    }
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p)
{
    free(((void**)p)[-1]);
}

void main (int argc, char *argv[])
{
    char **endptr;
    int *p = aligned_malloc (100, strtol(argv[1], endptr, 10));

    printf ("%s: %p\n", argv[1], p);
    aligned_free (p);
}

    You need an offset if you want to support alignments beyond what your system's malloc() does. For example if your system malloc() aligns to 8 byte boundaries, and you want to align to 16 bytes, you ask for 15 bytes extra so you know for sure you can shift the result around to align it as requested. You also add sizeof(void*) to the size you pass to malloc() to leave room for bookkeeping.

    ~(alignment - 1) is what guarantees the alignment. For example if alignment is 16, then subtract 1 to get 15, aka 0xF, then negating it makes 0xFF..FF0 which is the mask you need to satisfy the alignment for any returned pointer from malloc(). Note that this trick assumes alignment is a power of 2 (which practically it normally would be, but there really should be a check).

    It's a void**. The function returns void*. This is OK because a pointer to void is "A pointer to any type," and in this case that type is void*. In other words, converting void* to and from other pointer types is allowed, and a double-pointer is still a pointer.

    The overall scheme here is to store the original pointer before the one that's returned to the caller. Some implementations of standard malloc() do the same thing: stash bookkeeping information before the returned block. This makes it easy to know how much space to reclaim when free() is called.


Processes are managed by the kernel. The kernel doesn't care how the programmer allocates variables. All it knows is that certain blocks of memory belong to the process. The C runtime matches C memory management features to kernel features: automatic variables go into a memory block called “stack” and dynamic storage (malloc and friends) go into a memory block called “heap”. The process calls system calls such as sbrk and mmap to obtain memory with a granularity of MMU pages. Inside those blocks, the runtime determines where to put automatic varibles and dynamically allocated objects.

When a process dies, the kernel updates its memory management table to record, for each MMU page, that it is no longer in use by the process. This takes place no matter how the process exits, whether of its own violition (by calling a system call) or not (killed by a signal). Pages that are no longer used by any process are marked as reusable.

It's generally good hygiene to free the dynamically allocated storage that you're no longer using, because you never know when a piece of code might be reused in a long-running program. But when a process dies, the operating system will release all of its resources: memory, open file, etc.
