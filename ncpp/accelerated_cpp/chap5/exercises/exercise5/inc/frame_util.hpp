// header file

#ifndef _GUARD_FRAME_UTIL_HPP_
#define _GUARD_FRAME_UTIL_HPP_

#include <string>
#include <vector>

typedef std::vector<std::string> vec_string_type;
typedef std::string::size_type string_size_type;

string_size_type get_padding_width(const vec_string_type& input_strings);

vec_string_type create_frame(const vec_string_type& input_strings,
		const string_size_type padding);

#endif