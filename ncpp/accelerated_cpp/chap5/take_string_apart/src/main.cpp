// main file

#include <iostream>
#include <string>
#include <vector>
#include <cctype>  // isspace()

std::vector<std::string> split_string(const std::string& got_string);

int main(int argc, char **argv) {
	std::string take_input_string;
	std::cout << "Give a string as input: " << std::endl;
	getline(std::cin, take_input_string);
	std::vector<std::string> splitted_strings = split_string(take_input_string);
	std::cout << "Splitted Strings are: " << std::endl;
	for (std::string word: splitted_strings) {
		std::cout << word << std::endl;
	}
	return 0;
}

std::vector<std::string> split_string(const std::string& got_string) {
	std::vector<std::string> splitted_strings;
	typedef std::string::size_type string_size;
	string_size i = 0;
	// invariant: we have processed characters [original i, i)
	while (i != got_string.size()) {
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != got_string.size() && isspace(got_string.at(i))) {
			i++;
		}
		// find end of the next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j) is a space
		while (j != got_string.size() && !isspace(got_string.at(j))) {
			j++;
		}
		// if we found some non-whitespace characters
		if (i != j) {
			// copy from got_string starting from i to j - 1
			// first arg is starting point second is length for string.substr()
			splitted_strings.push_back(got_string.substr(i, j - i));
			i = j;
		}
	}
	return splitted_strings;
}