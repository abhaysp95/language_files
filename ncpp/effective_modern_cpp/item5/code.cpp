/** more on auto */

#include <iostream>
#include <memory>
#include <functional>
#include <vector>

/*template<typename IT>
void dwim(IT b, IT e) {
	while (b != e) {
		typename std::iterator_traits<IT>::value_type currvalue = *b;
		// do things
	}
}*/

/*int x1;    // potentially unintialized
auto x2;     // error! initialization required
auto x3 = 0; // fine, x's value is well-defined
int x4{};    // fine
auto x5{};   // not fine (initializer list empty)
auto x6{0};  // again, fine*/

/*template<typename IT>
void dwim(IT b, IT e) {
	while (b != e) {
		auto currvalue = *b;
		// do something
	}
}*/

class Widget {
	public:
		friend bool operator<(const Widget& lhs, const Widget& rhs);
};

// and because auto uses type deduction, it can represent types known only to compilers:
/*auto deref_up_less = [](const std::unique_ptr<Widget>& p1, std::unique_ptr<Widget>& p2) {
	return *p1 < *p2;
};*/

// but in C++14, you can also have parameters to lambda expressions auto too
/*auto deref_up_less = [](const auto& p1, const auto& p2) {
	return *p1 < *p2;
};*/


/** Just as you must specify the type of function to point to when you create a
 * function pointer(i.e., the signature of the functions you want to point to),
 * you must specify the type of function to refer to when you create a
 * std::function object. You do that through std::function's template
 * parameter. */

// to declare a std::function object named func that could
// refer to any callable object acting as if it had this
// signature
// bool (const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&)

// you'd write this
/*std::function<bool(const std::unique_ptr<Widget>&,
		const std::unique_ptr<Widget>&)> func;*/

/** because lambda expressions yield callable objects,
 * closures can be stored in std::function objects. That
 * means we could declare the C++11 version of deref_up_less
 * without using auto as follow: */


std::function<bool(const std::unique_ptr<Widget>&,
		const std::unique_ptr<Widget>&)> deref_up_less =  [](const std::unique_ptr<Widget>& p1,
			const std::unique_ptr<Widget>& p2) {
			return *p1 < *p2;
		};

// explicitly typed initializer idiom
/*std::vector<bool> features(const Widget& w);
Widget w;
auto high_priority = features(w)[5];*/
/** now, auto is supposed to deduce 'bool' but features(w) here returns std::vector<bool>::reference

  you therefore want to avoid code of this form:
  auto some_var = expression of "invisible" proxy class type
  The explicitly typed initializer idiom involves declaring a variable with auto, but casting the initialization expression to the type you want auto to deduce */
/*auto high_priority = static_cast<bool>features(w)[5];*/

/** So, the thing you would want to remember is that:
  1. "Invisible" proxy types can cause auto to deduce the "wrong" type for an initializing expression.
  2. The explicitly typed initializer idiom forces auto to deduce the type you want it to have */
