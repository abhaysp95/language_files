// cpp file for "test_processing_util.hpp"

#include "../inc/test_processing_util.hpp"

#include <algorithm>

vec_str_type get_ascenders_descenders_result(const vec_str_type& input_strings) {
	vec_str_type temp_if_ascenders_descenders_list{};
	for (const std::string& str: input_strings) {
		if (is_ascenders_present(str)
				&& is_descenders_present(str)) {
			temp_if_ascenders_descenders_list.push_back("true, ascenders & descenders present");
		}
		else if (is_ascenders_present(str)) {
			temp_if_ascenders_descenders_list.push_back("true, ascenders present");
		}
		else if (is_descenders_present(str)) {
			temp_if_ascenders_descenders_list.push_back("true, descenders present");
		}
		else {
			temp_if_ascenders_descenders_list.push_back("false");
		}
	}
	return temp_if_ascenders_descenders_list;
}

bool is_ascenders_present(const std::string& input_string) {
	for (str_const_iter iter = input_string.begin(); iter != input_string.end(); ++iter) {
		if ( *iter == 'b'
				|| *iter == 'd'
				|| *iter == 'f'
				|| *iter == 'h'
				|| *iter == 'k'
				|| *iter == 'l'
				|| *iter == 't') {
			return true;
		}
	}
	return false;
}

bool is_descenders_present(const std::string& input_string) {
	for (str_const_iter iter = input_string.begin(); iter != input_string.end(); ++iter) {
		if (*iter == 'g'
				|| *iter == 'j'
				|| *iter == 'p'
				|| *iter == 'q'
				|| *iter == 'y') {
			return true;
		}
	}
	return false;
}


vec_str_type largest_strings_without_ascenders_descenders(
		const vec_str_type& ascenders_descenders_result_list,
		const vec_str_type& input_strings) {
	vec_str_type max_len_str_without_ascenders_descenders{};
	str_size_type max_len_num{};
	for (vec_str_size_type i = 0; i < input_strings.size(); ++i) {
		if (ascenders_descenders_result_list.at(i).compare(0, 5, "false") == 0) {
			max_len_num = std::max(max_len_num, input_strings.at(i).size());
		}
	}
	for (vec_str_size_type i = 0; i < input_strings.size(); ++i) {
		if (ascenders_descenders_result_list.at(i).compare(0, 5, "false") == 0) {
			if (max_len_num == input_strings.at(i).size()) {
				max_len_str_without_ascenders_descenders.push_back(input_strings.at(i));
			}
		}
	}
	return max_len_str_without_ascenders_descenders;
}