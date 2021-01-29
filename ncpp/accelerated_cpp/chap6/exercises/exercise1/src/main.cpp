// main file

#include <iostream>

#include "../inc/frame_util.hpp"

int main(int argc, char **argv) {
	vec_str input_strings;
	std::string temp_str;
	while (std::getline(std::cin, temp_str)) {
		input_strings.push_back(temp_str);
	}
	std::cout << std::endl << "Generating Frame...\n" << std::endl;
	vec_str created_frame = create_frame(input_strings);
	for (const std::string& str: created_frame) {
		std::cout << str << "\n";
	}
	std::cout << std::endl;
	return 0;
}