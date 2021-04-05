// header file

#ifndef _GUARD_GEN_SEN_UTIL_HPP_
#define _GUARD_GEN_SEN_UTIL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>


typedef std::vector<std::string> Rule;
// is std::vector<std::vector<std::string> >
typedef std::vector<Rule> Rules;
// std::map<std::string, std::vector<std::vector<std::string> > >
typedef std::map<std::string, Rules> Grammer;

std::vector<std::string>
split(const std::string& input_str);

Grammer
read_grammer(std::istream& in);

std::vector<std::string>
gen_sentence(const Grammer& grammer);

void
gen_aux(const Grammer& grammer, const std::string& str, std::vector<std::string>& make_str);

bool
is_rule(const std::string& str);

size_t
nrand(size_t n);

#endif