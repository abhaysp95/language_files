// cpp file for "frame_util.hpp"

#include "../inc/frame_util.hpp"

#include <algorithm>

// get max padding length from the max length string entered
std::string::size_type get_max_width(const std::vector<std::string>& input_strings) {
	std::string::size_type max_len = 0;
	for (std::string string: input_strings) {
		max_len = std::max(max_len, string.size());
	}
	return max_len;
}

// create frame with all the input strings
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

// vertical concatenation of two frames(images)
std::vector<std::string> vcat(const std::vector<std::string>& top,
		const std::vector<std::string>& bottom) {
	std::vector<std::string> concatenated_vector = top;
	concatenated_vector.insert(concatenated_vector.end(), bottom.begin(), bottom.end());
	//above insert method is same for
	//for (std::vector<std::string>::const_iterator it = bottom.begin();
			//it != bottom.end(); ++it) {
		//concatenated_vector.push_back(*it);
	//}
	//the operation done with the help of for loop is a common operation,that's why
	//there's insert() method to reduce this redundent task
	return concatenated_vector;
}

// horizontal concatenation of two frames(images)
std::vector<std::string> hcat(const std::vector<std::string>& left,
		const std::vector<std::string>& right) {
	std::vector<std::string> concatenated_vector = left;
	// add 1 to leave space between pictures
	std::string::size_type width1 = get_max_width(left) + 1;
	std::vector<std::string>::size_type i{}, j{};
	// continue until all rows of both pictures are seen
	while (i != left.size() || j != right.size()) {
		// construct a new string
		std::string temp_string;
		// copy a row from LHS image, if there is one
		if (i != left.size()) {
			temp_string = left.at(i++);
		}
		temp_string += std::string(width1 - temp_string.size(), ' ');
		// copy a row from RHS image, if there is one
		if (j != right.size()) {
			temp_string += right.at(j++);
		}
		concatenated_vector.push_back(temp_string);
	}
	return concatenated_vector;
}