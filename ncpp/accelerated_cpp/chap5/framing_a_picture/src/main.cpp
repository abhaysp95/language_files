// main file

#include <iostream>
#include "../inc/frame_util.hpp"

#include <string>
#include <vector>

int main(int argc, char **argv) {
	std::string input_string;
	std::vector<std::string> input_strings;
	std::cout << "Enter the strings[press Ctrl-d to quit]: " << std::endl;
	while(getline(std::cin, input_string)) {
		input_strings.push_back(input_string);
	}
	std::cout << std::endl << "Generating Frame...\n" << std::endl;
	std::vector<std::string> created_frame = create_frame(input_strings);
	for (std::string str: created_frame) {
		std::cout << str << std::endl;
	}
	return 0;
}