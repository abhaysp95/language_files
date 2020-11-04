#include <iostream>

void f2(int& x);

int& f1() {
	static int x = 2;
	std::cout << "inside f1" << std::endl;
	std::cout << x << std::endl;
	f2(x);
	std::cout << x << std::endl;
	std::cout << "address of x(f1): " << (&x) << std::endl;
	return x;
}

void f2(int& x) {
	std::cout << "inside f2" << std::endl;
	std::cout << "address of x(f2): " << (&x) << std::endl;
	x++;
}

int main(int argc, char **argv) {
	int a = f1();
	a++;
	std::cout << "address of a: " << (&a) << std::endl;
	f1();
	return 0;
}

/* so, even though x is static it isn't incremented through main function
 * because, x is just getting copied to a, and x and a are having different
 * address so they are basically different and main is out of scope for x,
 * cause static int x is defined inside f1() not inside global translation unit
 * */
