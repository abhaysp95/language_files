// main file

#include <iostream>
#include <array>
#include <numeric>
#define SIZE 3

typedef std::array<int, SIZE> tarr;

void get_sum(const tarr& arr);

int main(int argc, char **argv) {
	tarr arr = {1, 2, 2};
	get_sum(arr);
	return 0;
}

void get_sum(const tarr& arr) {
	/*std::array<int, SIZE>::const_iterator first_begin{arr.begin()};
	do {
		std::array<int, SIZE>::const_iterator second_begin{first_begin};
		do {
			int sum{};
			// not right, because IDK but I think that having two different iterators is the problem
			sum = std::accumulate(first_begin, second_begin, 0);
			std::cout << "Sum: " << sum << '\n';
			second_begin++;
		} while (second_begin != arr.cend());
		first_begin++;
	} while (first_begin != arr.cend());*/

	for (tarr::size_type idx = 0; idx < arr.size(); ++idx) {
		int sum{};
		for (tarr::size_type sidx = idx; sidx < arr.size(); ++sidx) {
			sum += arr[sidx];
			std::cout << "Sum: " << sum << '\n';
		}
	}
	std::cout << std::endl;
}