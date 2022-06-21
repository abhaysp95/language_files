#include "box.hpp"

#include <iostream>

int main(void) {
	Box box{0,0,0};
	Box other_box{2, 3, 5};

	if (!box) {
		std::cout << "no volume\n";
	}
	if (other_box) {
		std::cout << other_box.volume() << std::endl;
	}

	return 0;
}
