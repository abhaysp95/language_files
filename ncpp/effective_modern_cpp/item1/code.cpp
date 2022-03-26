// type deduction for template

/*template<typename T>
void func(Paramtype param);

int x = 0;
f(x);  // f(expr)*/

// The type deduced by T is not just dependent on expr, but
// also on the form of Paramtype


// Case1: Paramtype is reference or pointer, but not universal reference

/*template<typename T>
void f(T& param);  // param is reference

int x = 27;        // x is int
const int cx = x;  // cx is const int
const int& rx = x; // rx is reference to x as const int

f(x);  // T is int, Paramtype is int&
f(cx); // T is const int, Paramtype is const int&
f(rx); // T is const int, Paramtype is const int&*/

// when we change the type of f's parameter from T& to const T&
/*template<typename T>
void f(const T& param);

int x = 27;
const int cx = x;
const int& rx = x;

f(x);  // T is int, param's type is const int&
f(cx); // T is int, param's type is const int&
f(rx); // T is int, param's type is const int&*/

// if param were pointer(or pointer to const) instead of reference
/*template<typename T>
void f(T* param);

int x = 27;         // x is int
const int* px = &x; // px is ptr to x as const int

f(&x);  // T is int, param's type is int*
f(px);  // T is const int, param's type is const int**/


// Case 2: Paramtype is universal reference

/**
  1. if expr is lvalue, both T and Paramtype are deduced to be lvalue references. That's doubly unusual. First, it's the only situation in template type deduction where T is deduced to be reference. Second, although Paramtype is declared using the syntax for rvalue reference, its deduced type is an lvalue reference.
  2. if expr is rvalue, the "norma"(case 1) rules apply. */

/*template<typename T>
void f(T&& param);  // param is now a universal reference

int x = 27;
const int cx = x;
const int& rx = x;

f(x);  // x is lvalue, so T is int&, param's type is int&
f(cx);  // cx is lvalue, T is const int&, param's type is const int&
f(rx);  // rx is lvalue, T is const int&, param's type is const int&
f(27);  // 27 is rvalue, T is int, param's type is int&&*/


// case 3: Paramtype is neither a pointer nor a reference

/** That means it's a pass-by-value. Parameter wiil be a copy of whatever is passed in - a completely new object.
  1. If expr, is a reference, ignore the reference part
  2. after ignorin reference-ness, if expr is const, ignore it too */

/*template<typename T>
void f(T param);

int x = 27;
const int cx = x;
const int& rx = x;
const char* const ptr = "Fun with ptrs";  // ptr is const pointer to const object

f(x);   // T is int, param type is int
f(cx);  // T is int, param type is int
f(rx);  // T is int, param type is int
f(ptr); // pass arg of type const char* const, but param type will const char* */


// Array Arguments

/** Because array parameters declarations are treated as if
 * they were pointer parameters, the type of an array that's
 * passed to a template function by value is deduced to be a
 * pointer type */

/*template<typename T>
void f(T param);

const char name[] = "J. P. Briggs";
const char* ptrToName = name;
f(name);  // name is array, but T is deduced to const char* (note: const-ness is not dropped here)*/

/** if function is declaring parameters that are references
 * to arrays, then the type deduced for T is the actual type
 * of the array! The type includes the size of the array */

/*template<typename T>
void f(T& param);

f(name);  // T will be of type const char(&)[13]*/


// Function arguments

/** Same as arrays, function types can decay into function
 * pointers, and everything regarding type deduction for
 * array applies here too */

/*void func(int, double);  // func type is void(int, double)
template<typename T>
void f1(T param);  // param passed by value

template<typename T>
void f2(T& param);  // param passed by reference

f1(func);  // param type deduced as ptr-to-func, void(*)(int, double)
f2(func);  // param type deduced as ref-to-func, void(&)(int, double)*/
