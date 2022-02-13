#include <iostream>
#include <string>
#include "maxdefault4.hpp"

int main()
{
	int i = 42;
	int const& ir = i;
	//ir = 3;  // can't do
	auto a = ir;
	a = 3;  // can do

	std::cout << max<double>(4, 7) << std::endl;
}
