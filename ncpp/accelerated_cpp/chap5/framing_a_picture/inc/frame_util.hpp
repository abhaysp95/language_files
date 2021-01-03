// header file

#ifndef _GUARD_FRAME_UTIL_HPP_
#define _GUARD_FRAME_UTIL_HPP_

#include <string>
#include <vector>

// get the max_width of all the strings for padding
std::string::size_type get_max_width(const std::vector<std::string>& input_strings);

// get the frame in form of vector
std::vector<std::string> create_frame(const std::vector<std::string>& input_strings);

// vertical concatenation
std::vector<std::string> vcat(const std::vector<std::string>& top,
		const std::vector<std::string>& bottom);

#endif