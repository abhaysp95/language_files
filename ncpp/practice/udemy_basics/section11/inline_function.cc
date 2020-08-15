// inline function are mostly used in header files
// if you have a simple function you don't want to waste time with function
// overhead with all the pushing and poping of the activation record
// although, too much inline will also lead to larger binaries if not used
// properly
// nowadays, compiler are sophisticated that they automatically get if this
// could/should be inline


#include <iostream>

inline int sum(int x, int y) {
	return x + y;
}

int main() {
	int x{10}, y{20};
	int z{sum(x, y)};
	std::cout << z << std::endl;
	return 0;
}
