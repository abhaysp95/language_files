// main file

#include <iostream>

template <typename T>
T add(T a, T b) {
	return a + b;
}

int main(int argc, char **argv) {
	std::cout << add(2, 3) << std::endl;
	std::cout << add(2.3, 4.5) << std::endl;
	return 0;
}