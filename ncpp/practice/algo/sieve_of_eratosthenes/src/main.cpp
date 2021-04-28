// main file

#include <iostream>
#include <vector>

using namespace std;

void print_primes(size_t range) {
	vector<size_t> arr(range - 1, 0);
	// since prime number are going to start from 2, and array index starts
	// from 0, you'll only need 49 boxes say for range upto 50, where first
	// block will contain number 2
	for (size_t i = 2; i * i < range; ++i) {
		if (arr.at(i - 2) != 0)
			continue;  // it is marked block
		size_t j = i;
		size_t num = i * j;
		while (num <= range) {
			if ((num - (num / i) * i) == 0)
				arr.at(num - 2) = 1;
			j += i;
			num = i * (j);
		}
	}
	for (vector<size_t>::size_type i = 0; i < range - 1; ++i) {
		if (arr.at(i) == 0)  // print untouched blocks
			cout << i + 2 << '\n';
	}
}

int main(int argc, char **argv) {
	size_t range{};
	cin >> range;
	print_primes(range);
	return 0;
}


// NOTE: every natural number is either a prime number or divisble by a prime number