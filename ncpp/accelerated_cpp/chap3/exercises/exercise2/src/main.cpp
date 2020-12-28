// main file

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>

int main(int argc, char **argv) {
	std::cout << "Enter the numbers to find quarters(end with eof): " << std::endl;
	double x{0.0};
	std::vector<double> stored_numbers;
	while (std::cin >> x) {
		stored_numbers.push_back(x);
	}
	sort(stored_numbers.begin(), stored_numbers.end());
	std::cout << std::endl;
	std::streamsize prec = std::cout.precision();
	std::cout << "Quartiles are: " << std::setprecision(5);
	for (double num: stored_numbers) {
		std::cout << num / 4 << std::endl;
	}
	std::cout << std::setprecision(prec) << std::endl;
	return 0;
}