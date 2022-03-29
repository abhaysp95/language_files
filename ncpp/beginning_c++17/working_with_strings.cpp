#include <iostream>
#include <cmath>
#include <cctype>

using namespace std::string_literals;

void string_objects() {
	// from std::string to c-style string
	std::string proverb {"Many a mickle makes a muckle."};

	// using c_str(), return type const char * (i.e., can't modify the string)
	const char *proverb_c_str = proverb.c_str();

	// new data() method (C++17 onwards), returns char * (if not std::string is const)
	const char *proverb_data = proverb.data();

	std::cout << "len: " << proverb.length() << '\n';

	// start from the given position
	std::string part_literal {proverb, 5};  // or you can put string literal instead of proverb too

	std::string (6, 'z');  // zzzzzz

	std::string phrase {proverb, 0, 13};  // initialize with 13 chars starting from index 0 (3rd arg is length)
}

void concatenating_strings() {
	// one of the new ways to concat two string literals
	std::string cc_str {"this"s + ", "s + "that"};  // use namespace std::string_literals for it to work

	// using append() method is alternative of using +=
	std::string first {"John"}, last {"Doe"};
	std::string sentence {"Your name is "};
	// sentence += first + " " + last + ".\n";  // or
	sentence.append(first).append(" ").append(last).append(".\n");

	std::string compliment {"~~~ What a beautiful name... ~~~"};
	sentence.append(compliment, 3, 22);  // append substring
	sentence.append(3, '!');  // repeated chars
}

void concatenating_strings_and_numbers() {
	const std::string result_string {"The result equals: "};
	double result = M_PI;
	// result_string += std::to_string(result);  // can't do this because result_string is const
	std::cout << result_string + std::to_string(result) << '\n';
	// can access string characters with [] or at() method (returns const reference)

	// range based loop with strings
	for (auto& c: result_string)
		std::cout << std::toupper(c);
	std::cout << '\n';

	// use std::getline(stream, string, delim) to get strings with spaces from input (3rd argument is optional and will be treated as delimiter)
}

void accessing_substrings() {
	std::string phrase {"The higher the fewer"};
	std::string word1 {phrase.substr(4, 6)};  // start index = 4, length 6
	std::string word2 {phrase.substr(4, 100)};  // goes upto end of string
	std::string word {phrase.substr(4)};  // starts from 4 and goes to end of string

	// if start index is out of range, exception std::out_of_range is thrown
}

// most containers beside std::string, like std::vector, std::array,
// std::optional<>, all smart pointers type and more offer swap() method.
// There's also template function std::swap() in utility header.
