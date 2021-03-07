// header file

#ifndef _GUARD_DAY2_UTIL_HPP_
#define _GUARD_DAY2_UTIL_HPP_

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> split_input(const std::string& input);
bool valid_passwords(const std::vector<std::string>& splitted_strings);
bool valid_passwords_part2(const std::vector<std::string>& splitted_strings);
std::vector<size_t> get_min_max(const std::string& input);
size_t count_of_char_appeared_in_passwd(const std::string& passwd, char* c);

#endif