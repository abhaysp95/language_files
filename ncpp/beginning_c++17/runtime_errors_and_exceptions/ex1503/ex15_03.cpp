#include "mytroubles.hpp"
#include <iostream>

void trySomething(int i);

int main(void) {
	for (int i {}; i < 2; i++) {
		try {
			trySomething(i);
		} catch (const Trouble& t) {
			std::cout << "Exception: " << t.what() << std::endl;
		}
	}

	return 0;
}

void trySomething(int i) {
	if (i == 0) {
		throw Trouble {};
	} else {
		throw Trouble {"Nobody knows the trouble I've seen..."};
	}
}
