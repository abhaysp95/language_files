// main file

#include "../inc/palindrome_util.hpp"

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **argv) {
	std::vector<std::string> input_strings;
	std::string input_string;
	std::cout << "Enter word/string to check if palindrome: " << std::endl;
	while (std::cin >> input_string) {
		input_strings.push_back(input_string);
	}
	std::vector<std::string> is_palindrome_list = create_palindrome_or_not_list(input_strings);
	for (std::vector<std::string>::size_type i = 0; i < input_strings.size(); ++i) {
		std::cout << input_strings.at(i) << ": " << is_palindrome_list.at(i) << std::endl;
	}
	std::cout << std::endl << "max len palindrome string/s: " << std::endl;
	std::vector<std::string> max_len_palindrome_strings = max_len_palindrome_list(
			is_palindrome_list, input_strings);
	for (std::string str: max_len_palindrome_strings) {
		std::cout << str << std::endl;
	}
	return 0;
}