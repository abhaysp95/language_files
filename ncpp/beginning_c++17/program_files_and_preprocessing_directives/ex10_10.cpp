// using static_assertion

#include <iostream>
#include <string>
#include <vector>
#include "average.h"

int main()
{
	std::vector<double> vectorData {2.34, 39.983, 934, 32.34, 493.23};
	std::cout << "average(double): " << average(vectorData) << '\n';

	// uncomment for compile-time error
	/* std::vector<std::string> words {"this", "that", "these", "those"};
	std::cout << "average(words): " << average(words) << '\n'; */

	std::vector<int> emptyVector {};
	std::cout << "average(empty): " << average(emptyVector) << std::endl;
}
