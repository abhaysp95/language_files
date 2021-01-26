// main file

#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <limits>

void give_result(const std::vector<int>& vec, const int& num);

int main(int argc, char **argv) {
	size_t count{};
	std::cin >> count;
	std::vector<int> vec(count, 0);
	for (int& num: vec) {
		std::cin >> num;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::sort(vec.begin(), vec.end());  // just in case(even though question is providing sorted)
	size_t q_count{};
	std::cin >> q_count;
	while (q_count--) {
		int num_to_find{};
		std::cin >> num_to_find;
		give_result(vec, num_to_find);
	}
	return 0;
}

void give_result(const std::vector<int>& vec, const int& num) {
	// no need to use find here cause lower_bound matches equality too unlike upper_bound
	//std::vector<int>::const_iterator pos = std::find(vec.begin(), vec.end(), num);
	/*if (pos != vec.end()) {
		std::cout << "Yes " << (pos - vec.begin() + 1) << "\n";
	}
	else {
		pos = std::lower_bound(vec.begin(), vec.end(), num);
		std::cout << "No " << (pos - vec.begin() + 1) << "\n";
	}*/
	std::vector<int>::const_iterator pos = std::lower_bound(vec.begin(), vec.end(), num);
	if (num == *pos) {
		std::cout << "Yes " << (pos - vec.begin() + 1) << "\n";
	}
	else {
		std::cout << "No " << (pos - vec.begin() + 1) << "\n";
	}
}