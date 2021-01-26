// main file

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
	size_t count{};
	std::cin >> count;
	std::vector<int> vec(count, 0);
	for (int& num: vec) {
		std::cin >> num;
	}
	std::sort(vec.begin(), vec.end());
	for (const int& num: vec) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	return 0;
}