// cpp file for "day2_util.hpp"

#include "../inc/day2_util.hpp"
#include <iostream>

std::vector<std::string> split_input(const std::string& input) {
	std::string::const_iterator first, second;
	//std::string number_of_times, char_to_appear, password;
	std::vector<std::string> string_parts;
	first = input.begin();
	while (first != input.end()) {
		// stop at the first character which is not space in the string
		first = std::find_if(first, input.end(), [](char c){ return !isspace(c); });
		// stop at the first character in the string which is space
		second = std::find_if(first, input.end(), [](char c){ return isspace(c); });
		if (first != input.end()) {
			string_parts.push_back(std::string(first, second));
			first = second;
		}
	}
	return string_parts;
}

/** in this splitted_strings parameter which is vector of string, there will only be 3 elements
  1. count of max and min, in form of <max>-<min>(1-3)
  2. char which should appear at max "max" and at min "min" times(a:)
  3. password itself
  */
bool valid_passwords(const std::vector<std::string>& splitted_strings) {
	size_t actual_count_of_char_in_passwd{};
	std::vector<size_t>min_max = get_min_max(splitted_strings.at(0));
	// no need to change to c_str() the splitted_strings.at(1) cause the standard
	// string type is just a wrapper around the c string type(I think)
	char char_to_appear = splitted_strings.at(1).at(0);
	// third is the password itself
	actual_count_of_char_in_passwd = count_of_char_appeared_in_passwd(splitted_strings.at(2), &char_to_appear);
	if ((actual_count_of_char_in_passwd >= min_max.at(0)) &&
			(actual_count_of_char_in_passwd <= min_max.at(1))) {
		return true;
	}
	return false;
}

/** now the question hasn't mentioned that what to do if the character also appears in any other
  positions than either of the two provided, so I'll treat it as valid password
  */
bool valid_passwords_part2(const std::vector<std::string>& splitted_strings) {
	// here get_min_max function will return two number just like before, but
	// these two numbers will act as two positions, in which exactly one position
	// should contain the character else the password will be invalid
	std::vector<size_t>two_positions = get_min_max(splitted_strings.at(0));
	std::string::size_type str_size = splitted_strings.at(2).size();
	char char_to_appear = splitted_strings.at(1).at(0);
	// since, I'm subtracting 1 while indexing the password, I'll check upto less than equals to
	if (two_positions.at(1) <= str_size) {
		if ((char_to_appear == splitted_strings.at(2).at(two_positions.at(0) - 1)) &&
				(char_to_appear != splitted_strings.at(2).at(two_positions.at(1) - 1))) {
			return true;
		}
		else if ((char_to_appear != splitted_strings.at(2).at(two_positions.at(0) - 1)) &&
				(char_to_appear == splitted_strings.at(2).at(two_positions.at(1) - 1))) {
			return true;
		}
	}
	return false;
}

/** input will be like this 12-45, 4-8 etc. */
std::vector<size_t> get_min_max(const std::string& input) {
	size_t max{}, min{}, count{};
	std::string::const_iterator first, second;
	first = input.begin();
	/** this loop should run only two times, one time for min and other for max */
	while (first != input.end()) {
		first = std::find_if(first, input.end(), [](char c){ return isdigit(c); });
		second = std::find_if(first, input.end(), [](char c){ return !isdigit(c); });
		if (first != input.end()) {
			if (count++ == 0) {
				// make a test program to check whether the following syntax is correct or not
				min = std::stoi(std::string(first, second));
			}
			else {
				max = std::stoi(std::string(first, second));
			}
			first = second;
		}
	}
	return {min, max};
}

size_t count_of_char_appeared_in_passwd(const std::string& passwd, char* c) {
	size_t count{};
	std::string::const_iterator citer = passwd.begin();
	while (citer != passwd.end()) {
		if (*citer == *c) {
			++count;
		}
		citer++;
	}
	return count;
}