// simple things on type conversion

#include <iostream>

void type_conversion() {
	bool b = 42;
	std::cout << "bool b: " << b << std::endl;
	int i = b;
	std::cout << "int i: " << i << std::endl;
	i = 3.14;
	std::cout << "int i with decimal value: " << i << std::endl;
	double pi = i;
	std::cout << "double pi with int value: " << pi << std::endl;
	unsigned char c = -1;
	std::cout << "unsigned char with -1: " << c << std::endl;
	signed char c2 = 256;
	std::cout << "signed char with value bigger than it's range: " << c2
		<< std::endl;
}

void test_conversion() {
	unsigned u = 10, u2 = 42;  // write unsigned like 10u
	std::cout << u2 - u << std::endl;  // 32
	std::cout << u - u2 << std::endl;  // something big postive(modulus)

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;  // 32
	std::cout << i - i2 << std::endl;  // -32  (int bydefault is signed)

	std::cout << i - u << std::endl;  // 0  (int will converted to unsigned)
	std::cout << u - i << std::endl;  // 0

	std::cout << i - u2 << std::endl;  // something big +ve (change will happen after the subtraction)
	std::cout << u2 - i << std::endl;  // 32, since result is +ve, so no conversion
}


int main() {
	type_conversion();
	std::cout << "\n" << std::endl;
	test_conversion();

	std::cout << "\nWriting a literal with octal and hexa-dec" << std::endl;
	std::cout << "Hi \x4dO\115!\n" << std::endl;  // prints MOM
	std::cout << "Who goes with F\145rgus?\012" << std::endl;
	return 0;
}
