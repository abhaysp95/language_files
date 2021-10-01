// A perfect factory method

/** A totatlly generic factory method. In particular, that means that
 * the function should have the following characterstics:
 * 1. Can take an arbitrary number of arguments
 * 2. Can accept lvalues and rvalues as an argument
 * 3. Forwards its arguments identical to the underlying constructor
 */

#include <iostream>
#include <string>
#include <utility>

// first iteration

/*template<typename T, typename Arg>
T create(Arg& a) {
	return T(a);
}*/

/** second iteration */
/*template<typename T, typename Arg>
T create(const Arg& a) {
	return T(a);
}*/
/*******************/

/** third iteration */
/*template<typename T, typename Arg>
T create(Arg&& a) {
	return T(std::forward<Arg>(a));
}

int main() {
	std::cout << std::endl;
	// lvalues
	int five = 5;
	int myFive = create<int>(five);
	std::cout << "myFive: " << myFive << std::endl;

	// rvalues
	int myFive2 = create<int>(5);
	std::cout << "myFive2: " << myFive2 << std::endl;

	std::cout << std::endl;
}*/
/******************/


/** Fourth iteration */
template<typename T, typename ...Args>
T create(Args&& ...args) {
	return T(std::forward<Args>(args)...);
}

struct MyStruct {
	MyStruct(int i, double d, std::string s) {}
};

int main() {
	std::cout << std::endl;

	// lvalues
	int five = 5;
	int myFive = create<int>(five);
	std::cout << "myFive: " << myFive << std::endl;

	std::string str{"Lvalue"};
	std::string str2 = create<std::string>(str);
	std::cout << "str2: " << str2 << std::endl;

	// Rvalues
	int myFive2 = create<int>(5);
	std::cout << "myFive2: " << myFive2 << std::endl;

	std::string str3 = create<std::string>(std::string("Rvalue"));
	std::cout << "str3: " << str3 << std::endl;

	std::string str4 = create<std::string>(std::move(str3));
	std::cout << "str4: " << str4 << std::endl;

	// arbitrary number of arguments
	double doub = create<double>();
	std::cout << "doub: " << doub << std::endl;

	MyStruct myStr = create<MyStruct>(2011, 3.14, str4);

	std::cout << std::endl;
}
/*********************/
