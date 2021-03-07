// main file

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../inc/day2_util.hpp"

void print(const std::vector<std::string>& vec_str);
bool is_password_valid(const std::string& got_input_line);

int main(int argc, char **argv) {
	std::ifstream input_values;
	input_values.open("./input_main.txt");
	std::string input_line;
	size_t valid_passwords_count{};
	while (getline(input_values, input_line)) {
		if (is_password_valid(input_line)) {
			valid_passwords_count++;
		}
	}
	std::cout << "valid password count: " << valid_passwords_count << std::endl;
	return 0;
}

void print(const std::vector<std::string>& vec_str) {
	for (const std::string& str: vec_str) {
		std::cout << str << "\n";
	}
	std::cout << std::endl;
}

bool is_password_valid(const std::string& got_input_line) {
	std::vector<std::string> splitted_parts;
	splitted_parts = split_input(got_input_line);
	//print(splitted_parts);
	/** use valid_passwords() for first part of the question */
	if (valid_passwords_part2(splitted_parts)) {
		std::cout << got_input_line << "\n";
		return true;
	}
	return false;
}