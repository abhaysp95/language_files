// generate random number with rand()

#include <iostream>
#include <cstdlib>  // for rand() function
#include <ctime>  // for time() function

using std::cout;
using std::endl;

int main() {
	int random_num {};
	size_t count {10};  // number of random number to generate
	size_t max {6};  // upper bound(inclusive)
	size_t min {1};  // lower bound(inclusive)

	// seed the random generator,
	// if you don't then you'll get the same number sequence every run

	cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
	srand(time(nullptr));  // this does increase the randomness

	for (int i{}; i < count; ++i) {
		random_num = rand() % max + min;
		cout << "now random: " << random_num << endl;
	}

	// number of processor clock ticks per second(no relation to above's random program)
	cout << "Clocks per sec: " << CLOCKS_PER_SEC << endl;

	return 0;
}
