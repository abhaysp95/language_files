// cpp file for "palindrome_util.hpp"

#include "../inc/palindrome_util.hpp"

#include <algorithm>

// creates a vector which contains for all strings either it is palindrome or not
// you can change this function to only store the palindrome strings but I chose not to
std::vector<std::string> create_palindrome_or_not_list(const std::vector<std::string>& input_strings) {
	std::vector<std::string> palindromes_list;
	for (std::vector<std::string>::const_iterator iter = input_strings.begin();
			iter != input_strings.end(); ++iter) {
		if (is_palindrome(*iter)) {
			palindromes_list.push_back("true");
		}
		else {
			palindromes_list.push_back("false");
		}
	}
	return palindromes_list;
}

// check if string is palindrome or not
bool is_palindrome(const std::string& string) {
	std::string::size_type string_size = string.size();
	std::string temp_string{};
	while (string_size > 0) {
		temp_string.push_back(string.at(string_size - 1));
		--string_size;
	}
	if (string.compare(temp_string) == 0) {
		return true;
	}
	return false;
}

// gives all the strings which are palindromes of max length
std::vector<std::string> max_len_palindrome_list(
		const std::vector<std::string> is_palindrome_list,
		const std::vector<std::string>& got_strings_list) {
	std::vector<std::string> max_len_palindromes{};
	std::string::size_type max_len_palindrome{};
	for (std::vector<std::string>::size_type i = 0; i != got_strings_list.size(); ++i) {
		if (is_palindrome_list.at(i).compare("true") == 0) {
			max_len_palindrome = std::max(max_len_palindrome, got_strings_list.at(i).size());
		}
	}
	for (const std::string& str: got_strings_list) {
		if (str.size() == max_len_palindrome) {
			max_len_palindromes.push_back(str);
		}
	}
	return max_len_palindromes;
}

bool compare(const std::string& str1, const std::string& str2) {
	return str1.size() > str2.size();
}