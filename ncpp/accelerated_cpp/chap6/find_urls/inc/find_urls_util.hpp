// header file

#ifndef _GUARD_FIND_URLS_UTIL_HPP_
#define _GUARD_FIND_URLS_UTIL_HPP_

#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;
typedef std::string::const_iterator str_const_iter;

vec_str find_urls(const std::string& str);
str_const_iter url_end(str_const_iter b, str_const_iter e);
bool not_url_char(char c);
str_const_iter url_beg(str_const_iter b, str_const_iter e);

#endif