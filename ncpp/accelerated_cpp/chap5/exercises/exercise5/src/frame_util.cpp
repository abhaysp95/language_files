// cpp file for "frame_util.hpp"

#include "../inc/frame_util.hpp"

#include <algorithm>

// get max_padding of all the input_strings
string_size_type get_padding_width(const vec_string_type& input_strings) {
	string_size_type max_len{};
	typedef std::vector<std::string>::const_iterator loop_iterator;
	for (loop_iterator iter = input_strings.begin();
			iter != input_strings.end(); ++iter) {
		max_len = std::max(max_len, iter->size());
	}
	return max_len;
}

// function to pad original picture to center
vec_string_type create_frame(const vec_string_type& input_strings,
		const string_size_type padding) {
	vec_string_type created_frame;
	string_size_type max_width = get_padding_width(input_strings);
	// insert top border
	created_frame.push_back(std::string(max_width + (padding * 2) + 2, '*'));
	// top padding for space
	string_size_type count = padding - 1;
	while (count > 0) {
		created_frame.push_back('*' + std::string(max_width + (2 * padding), ' ') + '*');
		--count;
	}
	for (vec_string_type::const_iterator iter = input_strings.begin();
			iter != input_strings.end(); ++iter) {
		string_size_type max_space_end = (max_width - iter->size()) % 2 == 0
			? (max_width - iter->size()) / 2
			: ((max_width - iter->size()) / 2) + 1;
		std::string space_padding(((max_width - iter->size()) / 2) + padding, ' ');
		created_frame.push_back("*"
				+ space_padding
				+ *iter
				+ std::string(max_space_end + padding, ' ')
				+ "*");
	}
	count = padding - 1;
	while (count > 0) {
		created_frame.push_back('*' + std::string(max_width + (2 * padding), ' ') + '*');
		--count;
	}
	// insert bottom border
	created_frame.push_back(std::string(max_width + (padding * 2) + 2, '*'));
	return created_frame;
}