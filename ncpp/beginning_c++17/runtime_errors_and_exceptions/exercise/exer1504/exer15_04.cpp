#include "curveball.hpp"
#include "numberexceptions.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <random>

size_t random(size_t);
void throws_exception();
int read_even_number();
void ask_even_number();

static std::mt19937_64 rang(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int main(void) {
	/* size_t count{};
	for (size_t i{}; i < 1000; ++i) {
		try {
			throws_exception();
		} catch(const CurveBall&) {
			count++;
		}
	}

	std::cout << "exception thrown: " << count << std::endl; */

	try {
		ask_even_number();
	} catch(const CurveBall&) {
		std::cout << "...hit it out of the park!" << std::endl;
	}

	return 0;
}

size_t random(size_t count) {
	std::uniform_int_distribution<size_t> rnd(0, count - 1);
	return rnd(rang);
}

void throws_exception() {
	if (random(100) < 25) {
		throw CurveBall{ "number less than 25" };
	}
}

int read_even_number() {
	throws_exception();  // 25% of times something goes wrong in this function

	int x{};
	std::cin >> x;

	if (std::cin.fail()) {  // will be true if x got any value other than int
		std::cin.clear();  // reset the failure state
		std::string line;  // read the errornous input and discard it
		std::getline(std::cin, line);

		throw NotANumber{};
	}

	if (x < 0) {
		throw NegativeNumber{};
	} else if ((x & 1) == 1) {
		throw OddNumber{};
	}

	return x;
}

void ask_even_number() {
	int x{};

	while (true) {
		std::cout << "Enter the value\nx: ";
		try {
			x = read_even_number();
			std::cout << "value entered: " << x << std::endl;
		} catch (const NotANumber& t) {
			std::cerr << "Exception: " << t.what() << "\nExiting!!!" << std::endl;
			return;
		} catch (const std::domain_error& t) {
			std::cerr << "Exception: " << t.what() << std::endl;
			std::cout << "Try again (even value preferred)" << std::endl;
		}
	}
}
