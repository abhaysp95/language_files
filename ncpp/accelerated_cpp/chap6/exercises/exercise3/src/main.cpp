// main file

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
	std::vector<int> u(10, 100), v, w, x;
	std::cout << "Elements in u: \n";
	for (const int& num: u) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	//std::copy(u.begin(), u.end(), v.begin());  // will give segfault
	//std::copy(u.begin(), u.end(), v.end());  // too will give segfault
	// correct way to copy using STL copy
	std::copy(u.begin(), u.end(), back_inserter(v));
	std::cout << "After copy elements in v: \n";
	for (const int& num: v) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	// another way of copying the elements
	std::vector<int>::const_iterator idx;
	idx = u.begin();
	while (idx != u.end()) {
		w.push_back(*idx++);  // *idx++ means *(idx++) means *idx -> idx++
	}
	std::cout << "After copy elements in w: \n";
	for (const int& num: w) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	x.insert(x.end(), u.begin(), u.end());
	std::cout << "After copy elements in x: \n";
	for (const int& num: x) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	return 0;
}