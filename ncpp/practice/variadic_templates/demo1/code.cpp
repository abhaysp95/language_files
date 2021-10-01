// https://eli.thegreenplace.net/2014/variadic-templates-in-c/

#include <iostream>
#include <cmath>
#include <limits>

/** basic example */

/** this follows C++'s usual template and overload resolution rule */
template<typename T>  // base case
T adder(T v) {
	std::cout << __PRETTY_FUNCTION__ << '\n';
	return v;
}

template<typename T, typename... Args>  // general case
T adder(T first, Args... args) {
	std::cout << __PRETTY_FUNCTION__ << '\n';
	//std::cout << __func__ << '\n';
	return first + adder(args...);
}
// 'typename...' is 'template parameter pack' and 'Args... args' is 'function parameter pack'

/** Variadic templates are written in just the way you would write recursive
 * code - you need a base case and a general case */

void caller() {  // this will work properly as long as + operator can be used with the types
	int r1 = adder(1, 2, 3, 4, 5);
	std::string s1{"x"}, s2{"aa"}, s3{"xx"}, s4{"yyy"};
	std::string r2 = adder(s1, s2, s3, s4);
	std::cout << r1 << ", " << r2 << std::endl;
}


/** Pair comparer */
template<typename T>  // if odd number of pairs provided
bool pair_comparer(T a) { return false; }

template<typename T>
bool pair_comparer(T a, T b) { return a == b; }

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
	return (a == b) && pair_comparer(args...);
}

template<>
bool pair_comparer(float a, float b) {
	return fabs(a - b) > std::numeric_limits<double>::epsilon();
}
/** the above implementation will only work, when the pair elements getting
 * compared are of same type */

void caller2() {
	std::cout << (pair_comparer(2, 4, 3.5, 9.6, 10) ? "TRUE" : "FALSE") << '\n';
	std::cout << (pair_comparer(9, 9, 3) ? "TRUE" : "FALSE") << '\n';
	std::cout << (pair_comparer(9, 9, 3, 3) ? "TRUE" : "FALSE") << '\n';
	std::cout << (pair_comparer(4, 4, 8, 8, 9.3, 9.32) ? "TRUE" : "FALSE") << '\n';
	std::cout << (pair_comparer(4, 4, 8, 8, 9.3234, 9.3234) ? "TRUE" : "FALSE") << '\n';
}

int main(int argc, char** argv) {
	caller();
	caller2();
	return 0;
}
