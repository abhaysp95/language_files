// header file

#ifndef _GUARD_PALINDROME_UTIL_HPP_
#define _GUARD_PALINDROME_UTIL_HPP_

#include <vector>
#include <string>

std::vector<std::string> create_palindrome_or_not_list(const std::vector<std::string>& input_strings);

bool is_palindrome(const std::string& string);

std::vector<std::string> max_len_palindrome_list(
		const std::vector<std::string> is_palindrome_list,
		const std::vector<std::string>& got_strings_list);

bool compare(const std::string& str1, const std::string& str2);

#endif