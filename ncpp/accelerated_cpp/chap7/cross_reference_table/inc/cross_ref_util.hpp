// header file

#ifndef _GUARD_CROSS_REF_UTIL_HPP_
#define _GUARD_CROSS_REF_UTIL_HPP_

#include <vector>
#include <string>
#include <map>

using namespace std;

typedef std::vector<std::string> vstr;

vstr split(const std::string& str);

bool is_not_space(const char& c);
bool is_space(const char& c);

map<string, vector<size_t> > xref( istream& in, vstr find_words(const string& str) = split );

#endif