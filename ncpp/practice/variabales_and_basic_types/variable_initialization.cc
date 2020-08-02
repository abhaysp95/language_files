// initialization of variable

#include <iostream>

int main() {
	// different ways to initialize
	int a = 0;
	int b = {0};
	int c{0};  // this braced form of initialization is known as list initialization
	int d(0);
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "d is: " << d << std::endl;

	// with braced form of initialization, compiler will not let us initialize
	// variables of built-in tpye if the initializer might lead to the loss of
	// information
	long double ld = 3.1215926536;
	// can't use a,b,c,d, or it'll be the redefinition of them
	int e{ld}, f = {ld};  // error: narrowing conversion required [-Wnarrowing]
	int g(ld), h = ld; // ok, but value will be truncated
	std::cout << "e is: " << e << std::endl;
	std::cout << "f is: " << f << std::endl;
	std::cout << "g is: " << g << std::endl;
	std::cout << "h is: " << h << std::endl;
	return 0;
}
