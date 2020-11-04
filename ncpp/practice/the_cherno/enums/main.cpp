#include <iostream>

// you can also give enum type, default are int(32bit or something)
enum Example : unsigned char {
	// bydefault start from 0
	A = 5, B, C
};

int main(int argc, char **argv) {
	Example v = B;  // having Example as type means you can't set any other thing to v, it should be what's in enum, but with some other, like int you can set any other value which is normal behaviour
	if (v == 6) {
		std::cout << "here: " <<  static_cast<int>(v) << std::endl;
	}
	return 0;
}
