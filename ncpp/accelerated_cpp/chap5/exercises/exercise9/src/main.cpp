// main file

#include <iostream>
#include <cctype>

std::string make_lowercase(const std::string& got_word) {
	typedef std::string::size_type string_size_type;
	std::string new_string{};
	string_size_type str_size = 0;
	while (str_size != got_word.size()) {
		if (!islower(got_word.at(str_size))) {
			new_string += std::tolower(got_word.at(str_size));
		}
		++str_size;
	}
	return new_string.size() == 0 ? got_word : new_string;
}

std::string make_upppercase(const std::string& got_word) {
	typedef std::string::size_type string_size_type;
	std::string new_string{};
	string_size_type str_size = 0;
	while (str_size != got_word.size()) {
		if (!isupper(got_word.at(str_size))) {
			new_string += std::toupper(got_word.at(str_size));
		}
		++str_size;
	}
	return new_string.size() == 0 ? got_word : new_string;
}

int main(int argc, char **argv) {
	std::cout << "Provide inputs: " << std::endl;
	std::string word;
	while (std::cin >> word) {
		std::cout << word << ": " << make_lowercase(word)
			<< ", " << make_upppercase(word) << std::endl;
	}
	return 0;
}