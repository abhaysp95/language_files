// main file

#include "../inc/test_processing_util.hpp"

#include <iostream>
#include <algorithm>
#include <iomanip>

void print_list(const vec_str_type& result_list);
void print_list(const vec_str_type& result_list, const vec_str_type& got_strings);

int main(int argc, char **argv) {
	vec_str_type input_strings{};
	std::string input_string;
	while (std::cin >> input_string) {
		input_strings.push_back(input_string);
	}
	vec_str_type result_ascenders_descenders_data
		= get_ascenders_descenders_result(input_strings);
	std::cout << std::endl
		<< "Result if ascenders or descenders present in provided inputs: " << std::endl;
	print_list(result_ascenders_descenders_data, input_strings);
	std::cout << std::endl
		<< "Max len string/s without any ascenders or descenders: " << std::endl;
	vec_str_type max_str_list_without_ascenders_descenders
		= largest_strings_without_ascenders_descenders(
				result_ascenders_descenders_data,
				input_strings);
	print_list(max_str_list_without_ascenders_descenders);
	return 0;
}

void print_list(const vec_str_type& result_list, const vec_str_type& got_strings) {
	str_size_type max_len_string{};
	for (vec_str_const_iter iter = got_strings.begin(); iter != got_strings.end(); ++iter) {
		max_len_string = std::max(max_len_string, iter->size());
	}
	for (vec_str_size_type i = 0; i != got_strings.size(); ++i) {
		std::cout << std::left << std::setfill(' ') << std::setw(max_len_string + 1)
			<< got_strings.at(i) << ": " << result_list.at(i) << std::endl;
	}
}

void print_list(const vec_str_type& result_list) {
	for (const std::string& str: result_list) {
		std::cout << str << std::endl;
	}
}