// header file

#ifndef _GUARD_DEMO_UTIL_HPP_
#define _GUARD_DEMO_UTIL_HPP_

#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;

void biggies(vec_str& words, const vec_str::size_type sz);
void elimDups(vec_str& words);
bool isShorter(const std::string& word1, const std::string& word2);
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending);

#endif