// header file

#ifndef _GUARD_FRAME_UTIL_HPP_
#define _GUARD_FRAME_UTIL_HPP_

#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;
typedef std::vector<std::string>::const_iterator vec_str_const_iter;

std::string::size_type get_max_padding(const vec_str& input_strings);
std::string construct_frame_string(const std::string& str, const std::string::size_type& max_len_padding);
vec_str create_frame(const vec_str& input_strings);
vec_str vcat(const vec_str& top, const vec_str& bottom);
vec_str hcat(const vec_str& left, const vec_str& right);

#endif