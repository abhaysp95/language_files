// cpp file for "cross_ref_util.hpp"

#include "../inc/cross_ref_util.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

vstr split(const string& str) {
	vstr temp{};
	string::const_iterator first = str.cbegin();
	string::const_iterator second = str.cbegin();

	while (first != str.cend()) {
		first = find_if(first, str.cend(), is_not_space);  // move until predicate yields true
		second = find_if(first, str.cend(), is_space);

		if (first != str.cend()) {  // this means that
			temp.push_back(string{first, second});
		}

		first = second;
	}
	return temp;
}

bool is_space(const char& c) {
	return isspace(c);
}

bool is_not_space(const char& c) {
	return !isspace(c);  // if space found return false
}

// split function is used as def. argument
map<string, vector<size_t> > xref( istream& in, vstr find_words(const string& str)) {
	map<string, vector<size_t> > ref_table{};
	size_t line_count{};
	string new_string{};

	while (getline(in, new_string)) {
	//while (in.eof()) {
		//getline(in, new_string);
		vstr split_words = find_words(new_string);
		line_count++;
		for (vstr::const_iterator citer = split_words.cbegin(); citer != split_words.cend(); ++citer) {
			ref_table[*citer].push_back(line_count);  // ref_table[*citer] will return related vector<size_t>
		}
	}

	return ref_table;
}