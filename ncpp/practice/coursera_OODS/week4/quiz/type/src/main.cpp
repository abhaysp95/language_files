// main file

#include <iostream>

template <typename Type>
Type max(Type a, Type b) {
	return (a > b) ? a : b;
}

class just_a_double {
	public:
		double num;
		just_a_double(double x): num(x) {}  // The initializer list allows member variable constructor
		just_a_double(): just_a_double(0) {}
};

int main(int argc, char **argv) {
	just_a_double a, b;
	a.num = 5.0;
	b.num = 10.0;
	just_a_double c, d(100);
	std::cout << max<double>(a.num, b.num) << std::endl;
	std::cout << max(a.num, b.num) << std::endl;
	std::cout << c.num << std::endl;
	std::cout << d.num << std::endl;
	/* both are correct */
    return 0;
}