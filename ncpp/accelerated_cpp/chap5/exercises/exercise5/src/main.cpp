// main file

#include <iostream>
#include "../inc/frame_util.hpp"

#include <vector>
#include <string>

int main(int argc, char **argv) {
	std::string input_string;
	vec_string_type input_strings;
	std::cout << "Enter the strings[press Ctrl-d to quit]: " << std::endl;
	while(getline(std::cin, input_string)) {
		input_strings.push_back(input_string);
	}
	std::cout << std::endl << "Generating Frame...\n" << std::endl;
	vec_string_type created_frame = create_frame(input_strings, 5);
	for (std::string str: created_frame) {
		std::cout << str << std::endl;
	}
	return 0;
}