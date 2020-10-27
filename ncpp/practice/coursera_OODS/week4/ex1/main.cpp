#include <iostream>
#include <vector>

int main(int argc, char **argv) {
	std::vector<int> *v = new std::vector<int>;
	v -> push_back(1);
	v -> push_back(3);
	v -> push_back(5);
	std::cout << v -> at(0) << std::endl;
	std::vector<int> w;
	w.push_back(10);
	w.push_back(11);
	std::cout << w.at(0) << std::endl;
	std::cout << w[1] << std::endl;
	return 0;
}
