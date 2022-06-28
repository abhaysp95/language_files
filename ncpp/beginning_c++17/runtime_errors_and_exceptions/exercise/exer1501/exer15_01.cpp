#include "curveball.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>

size_t random(size_t);
void throws_exception();

int main(void) {
	std::srand(static_cast<unsigned>(std::time(0)));

	size_t count{};
	for (size_t i{}; i < 1000; ++i) {
		try {
			throws_exception();
		} catch(const CurveBall&) {
			count++;
		}
	}

	std::cout << "exception thrown: " << count << std::endl;
	return 0;
}

size_t random(size_t count) {
	return static_cast<size_t>(rand() / (RAND_MAX / (count + 1)));  // [0, count)
}
// generalized: M + rand() / (RAND_MAX / (N - M + 1) + 1);  // [M, N]

void throws_exception() {
	if (random(100) < 25) {
		throw CurveBall{ "number less than 25" };
	}
}

