// main file

/**
  * Problem statement
  *
  * you're provided with 7 char string having F and B chars only, this 7 char string
  * will represent number from 128 places(from 0 to 127). Depending on the char you'have
  * to find the number represented by that string. For example:
  * String: FBFBBFF will give 44
  */

#include <iostream>
#include <string>

#include "../inc/bsp_util.hpp"

int main(int argc, char **argv) {
	std::string str;
	std::cout << "Enter the string with F/B: ";
	std::cin >> str;
	std::string::const_iterator str_beg{str.begin()}, str_end{str.end()};
	size_t res = get_place(str_beg, str_end, 0, 127);
	std::cout << "result: " << res << std::endl;
	return 0;
}