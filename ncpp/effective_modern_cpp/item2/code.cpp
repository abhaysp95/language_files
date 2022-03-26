#include <vector>

template<typename T> struct TD;

/** Item2: Understand auto type deduction */

/**
  -> pretty much same to template type deduction, with only one curious
  exception
  -> there's a direct mapping between template type deduction and auto type
  deduction.
  -> when a variable is declared using auto, auto plays role of T in the
  template, and the type specifier for the variable acts as a ParamType
  */

/*auto x = 27;  // here, type specifier of x is simple auto itself
const auto cx = x;  // here the type specifier is const auto
const auto& rx = x;  // here, the type specifier is const auto&*/

// to deduce types for x, cx, and rx for example, compilers act as if there were a template for each declaration as well as a call to that template with corresponding initializing expression
/*template<typename T>
void ffx(T param);  // conceptual template deducing x's type
ffx(27);  // conceptual call: param's deduced types is x's type


template<typename T>
void ffcx(const T param);
ffcx(x);

template<typename T>
void ffrx(const T& param);
ffrx(x);*/


/** Since, auto type dedcution is same as template type deduction, in variable declaration using auto, the type specifier takes the place of ParamType, so there are three cases for that, too:
  1. the type specifier is a pointer or reference, but not a universal reference
  2. the type specifier is universal reference
  3. the type specifier is neither pointer nor a reference */

// we have already seen case 1 and 3

/*auto x = 27;        // case 3(x is neither ptr nor ref)
const auto cx = x;  // case 3(cx isn't either)
const auto& rx = x; // case 1(rx is non-universal ref)*/

// case 2 works as expected too:

/*auto&& uref1 = x;  // x is int and lvalue, so uref1's type is int&
auto&& uref2 = cx; // cx is const int and lvalue, so uref2's type is const int&
auto&& uref3 = rx; // rx is const int& and lvalue, so uref3's type is const int&
auto&& uref3 = 27; // 27 is int and rvalue, so uref3's type is int&&*/

/** same deduction technique is as template type dedcution
 * for array and function is used here too */
/*const char name[] = "This is something";  // name's type is const char[13]
auto arr1 = name;  // arr1's type is const char*
auto& arr2 = name;  // arr2's type is const char (&)[17];

void some_func(int, double);  // some_func's type is (void)(int, double)
auto func1 = some_func;   // func1's type is void(*)(int, double)
auto& func2 = some_func;   // func2's type is void(&)(int, double);*/

// Now, let's talk about one exception which makes auto-type deduction different from template type deduction

// from C++98, to declare and initialize a value
/*int x1 = 27;
int x2(27);*/
// C++11, througght its support for uninform initialization, adds these:
/*int x3 = {27};
int x4{27};*/
// all 4 syntaxes, one result: int with value 27

// there are advanatages to declaring variables using auto instead of fixed types

/*auto x1 = 27; // type is int, value is 27
auto x2(27);    // same as above
auto x3 = {27}; // type is std::initializer_list<int>, value is {27}
auto x4{27};    // same as above
auto x5 = {1, 2, 3.0};  // error*/

/** here's how auto type deduction for initializer_list is
 * similar to template type deduction. There are actually two
 * kind of type deduction going on, one deducts that it's
 * std::initializer_list, but std::initializer_list is
 * template as std::initializer_list<T> for some type T, that
 * means that T's type must also be deduced */

/*auto x = {11, 23, 9};  // x's type is std::initializer_list<int>
template<typename T>  // template with declaration equivalent to x's declaration
void f(T param);
f({1, 2, 3});  // error! can't deduce type for T

// but, below will work
template<typename T>
void f(std::initializer_list<T> param);
f({1, 2, 3});*/

// Apart from above, C++14 also provides auto to indicate that a function's return type should be deduced, and C++14 lambdas may use auto in parameter declarations. These auto use template type deduction, not auto type deduction. So, these won't work
/*auto create_init_list() {
	return {1, 2, 3, 4};  // error: can't deduce type for {1, 2, 3, 4}
}
// same for auto used in parameter type specification in C++14 lambda
std::vector<int> v;
auto reset_v = [&v](const auto& new_value) { v = new_value; }*/

/*auto test() {
	auto x = {1, 2, 3, 4};
	TD<decltype(x)> td;
	// you can't do something like std::initializer_list<auto>
}*/

/*// C++11
template<typename T>
auto test1(std::initializer_list<T>& x) -> decltype(x)
{
	return x;
}

// C++14
decltype(auto) test() {
	std::initializer_list<int> x = {1, 2, 3};
	return x;
}*/

/** The use of decltype(auto) is not limited to function
 * return types. It can also be convenient for declaring
 * variables when you want to apply the decltype deduction
 * rules */

class Widget {

};

/*Widget w;
const Widget& cw = w;
auto my_widget1 = cw;           // auto type deduction, type is Widget
decltype(auto) my_widget2 = cw; // auto type deduction, type is const Widget&*/

// C++14
/*template<typename Container, typename Index>
decltype(auto) auth_and_access(Container&& c, Index i) {
	// authenticate_user();
	return std::forward<Container>(c)[i];
}*/

template<typename Container, typename Index>
auto auth_and_access(Container&& c, Index i) -> decltype(std::forward<Container>(c)[i])
{
	// authenticate_user();
	return std::forward<Container>(c)[i];
}
