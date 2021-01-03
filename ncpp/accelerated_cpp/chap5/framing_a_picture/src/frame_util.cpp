// cpp file for "frame_util.hpp"

#include "../inc/frame_util.hpp"

#include <algorithm>

std::string::size_type get_max_width(const std::vector<std::string>& input_strings) {
	std::string::size_type max_len = 0;
	for (std::string string: input_strings) {
		max_len = std::max(max_len, string.size());
	}
	return max_len;
}

std::vector<std::string> create_frame(const std::vector<std::string>& input_strings) {
	std::vector<std::string> frames_per_line;
	std::string::size_type max_len_string = get_max_width(input_strings);
	std::string border(max_len_string + 4, '*');

	// write top border
	frames_per_line.push_back(border);

	// write each interior with border(consisting of spaces and asterisks)
	for (std::vector<std::string>::size_type i = 0; i != input_strings.size(); ++i) {
		frames_per_line.push_back("* " + input_strings.at(i)
				+ std::string((max_len_string - input_strings.at(i).size()), ' ') + " *");
	}

	// write bottom border
	frames_per_line.push_back(border);
	return frames_per_line;
}