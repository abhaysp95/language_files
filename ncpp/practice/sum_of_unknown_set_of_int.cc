// sum for the unkown set of integers, but sum only odd prime numbers

#include <iostream>

int get_prime(int number, int count) {
	if (number == 2) {
		return 0;
	}
	if (count <= 1) {
		// 1 is not a prime number
		return (number == 1) ? 1 : 0;
	}
	if (number % count == 0) {
		return 1;
	}
	return get_prime(number, count - 1);
}

bool get_prime1(int number, int count = 2) {
	if (number <= 2) {
		return (number == 2) ? true : false;
	}
	if (number % count == 0) {
		return false;
	}

	// no factor left for the number now
	if (count * count >= number) {
		return true;
	}
	return get_prime1(number, count + 1);
}

int main() {
	int value = 0, is_prime = 0, sum = 0;
	std::cout << "Enter the set of integers, do EOF to exit" << std::endl;
	while (std::cin >> value) {
		if (value % 2 != 0) {
			is_prime = get_prime1(value);

			// as false is 0, and true is a positive non-zero int
			if (is_prime == 1) {
				sum += value;
			}
		}
	}
	std::cout << "Sum of the odd prime numbers from the given set is " << sum
		<< std::endl;
	return 0;
}
