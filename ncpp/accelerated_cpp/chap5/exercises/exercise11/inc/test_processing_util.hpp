// header file

#ifndef _GUARD_TEST_PROCESSING_UTIL_HPP_
#define _GUARD_TEST_PROCESSING_UTIL_HPP_

#include <vector>
#include <string>

typedef std::vector<std::string> vec_str_type;
typedef std::vector<std::string>::const_iterator vec_str_const_iter;
typedef std::vector<std::string>::size_type vec_str_size_type;
typedef std::string::const_iterator str_const_iter;
typedef std::string::size_type str_size_type;

vec_str_type get_ascenders_descenders_result(const vec_str_type& input_strings);

bool is_ascenders_present(const std::string& input_string);

bool is_descenders_present(const std::string& input_string);

vec_str_type largest_strings_without_ascenders_descenders(
		const vec_str_type& ascenders_descenders_result_list,
		const vec_str_type& input_strings);

#endif