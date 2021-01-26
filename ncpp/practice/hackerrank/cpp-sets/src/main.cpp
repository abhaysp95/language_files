// main file

#include <iostream>
#include <set>
#include <algorithm>

int main(int argc, char **argv) {
	std::set<int> myset;
	size_t queries{};
	std::cin >> queries;
	int val{};
	while (queries--) {
		size_t type{};
		std::cin >> type;
		switch (type) {
			case 1:
				std::cin >> val;
				myset.insert(val);
				break;
			case 2:
				std::cin >> val;
				myset.erase(val);
				break;
			case 3:
				std::cin >> val;
				std::cout << (myset.find(val) != myset.end() ? "Yes" : "No") << "\n";
				break;
			default:
				break;  // do nothing
		}
	}
	std::cout << std::endl;
	return 0;
}