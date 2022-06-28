#include "curveball.hpp"
#include "toomanyexceptions.hpp"

#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>

size_t random(size_t);
void throws_exception();

// is this a bad idea ?
static std::mt19937_64 rang(std::chrono::high_resolution_clock::now()
		.time_since_epoch().count());

int main(void) {
	// std::srand(static_cast<unsigned>(std::time(0)));

	size_t count{};
	for (size_t i{}; i < 1000; ++i) {
		try {
			throws_exception();
		} catch(const CurveBall&) {
			count++;
			/* if (count == 10) {
				throw TooManyExceptions();
			} */
		}
	}

	std::cout << "exception thrown: " << count << std::endl;
	return 0;
}

size_t random(size_t count) {
	// return static_cast<size_t>(rand() / (RAND_MAX / (count + 1)));  // [0, count)
	std::uniform_int_distribution<size_t> rnd(0, count - 1);
	return rnd(rang);
}
// generalized: M + rand() / (RAND_MAX / (N - M + 1) + 1);  // [M, N]

void throws_exception() {
	if (random(100) < 25) {
		throw CurveBall{ "number less than 25" };
	}
}

