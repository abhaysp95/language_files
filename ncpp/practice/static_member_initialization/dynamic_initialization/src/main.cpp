// main file

#include <iostream>
#include <string>


//constexpr auto VERSION = std::string("3.4.1");
// constexpr variable can't have non-literal type
const auto VERSION = std::string("3.4.1"); // dynamic initialization

int main(int argc, char **argv) {
	std::cout << VERSION << std::endl;
	return 0;
}