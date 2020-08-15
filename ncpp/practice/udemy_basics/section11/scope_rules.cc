// you know the basics, going to show you the static local variable
// this preserves the previous value of the local variable every time the
// function is called

#include <iostream>

void static_local_example(int number) {
	static size_t static_variable {1000}; // on next call of this function,
	// static_variable willn't be initialized again
	static_variable += number;
	std::cout << "current value is: " << static_variable << std::endl;
}

int main() {
	static_local_example(400);
	static_local_example(500);
	return 0;
}
