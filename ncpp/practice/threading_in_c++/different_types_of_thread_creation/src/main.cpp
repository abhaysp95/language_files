// main file

#include <iostream>
#include <thread>

void fun(int x) {
	while (x-- > 0)
		std::cout << x << ' ';
	std::cout << std::endl;
}

// a basic functor(function object)
class Base {
	public:
		void operator()(int x) {
			while (x-- > 0)
				std::cout << x << ' ';
			std::cout << std::endl;
		}
};

// a basic non-static member function example
class ABase {
	public:
		void run(int x) {
			while (x-- > 0)
				std::cout << x << ' ';
			std::cout << std::endl;
		}
};

// a basic static member function example
class BBase {
	public:
		static void run(int x) {
			while (x-- > 0)
				std::cout << x << ' ';
			std::cout << std::endl;
		}
};

int main(int argc, char **argv) {
	/** Function pointer
	std::thread t1(fun, 10);
	t1.join();
	*/

	/** lambda function
	auto tfun = [](int x) {
		while (x-- > 0)
			std::cout << x << ' ';
		std::cout << std::endl;
	};
	std::thread t1(tfun, 10);
	t1.join(); */

	// you can directly inject lambda function to thread
	/** std::thread t1([](int x) {
				while (x-- > 0)
					std::cout << x << ' ';
				std::cout << std::endl;
			}, 10);
	t1.join(); */


	/** Using functor
	std::thread t1((Base()), 10);
	t1.join(); */


	/** non-static member function
	ABase ab;
	std::thread t1(&ABase::run, &ab, 10);
	t1.join(); */


	/** static member function */
	// you don't need a object for static member function
	std::thread t1(&BBase::run, 10);
	t1.join();

	return 0;
}