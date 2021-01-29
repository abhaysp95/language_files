// cpp file for "frame_util.hpp"

#include "../inc/frame_util.hpp"

#include <limits>
#include <ios>
#include <algorithm>

// get max padding length with max length string entered

std::string::size_type get_max_padding(const vec_str& input_strings) {
	std::string::size_type max_len{std::numeric_limits<std::string::size_type>::min()};
	for (vec_str_const_iter i = input_strings.begin(); i != input_strings.end(); ++i) {
		if (max_len < i->size()) {
			max_len = i->size();
		}
	}
	return max_len;
}

std::string construct_frame_string(const std::string& str,
		const std::string::size_type& max_len_padding) {
	return std::string("* " + str + std::string(max_len_padding - str.size() + 1, ' ') + "*");
}

vec_str create_frame(const vec_str& input_strings) {
	vec_str frames_per_line;
	std::string::size_type max_len_border = get_max_padding(input_strings);
	std::string top_bottom_border = std::string(max_len_border + 4, '*');
	frames_per_line.push_back(top_bottom_border);
	//std::transform(input_strings.begin(), input_strings.end(), back_inserter(frames_per_line), construct_frame_string);
	std::transform(input_strings.begin(), input_strings.end(), back_inserter(frames_per_line),
			[=](std::string result){
				return construct_frame_string(result, max_len_border);
			});
	frames_per_line.push_back(top_bottom_border);
	return frames_per_line;
}

vec_str vcat(const vec_str& top, const vec_str& bottom) {
	vec_str concatenated_vec(top.begin(), top.end());
	concatenated_vec.insert(concatenated_vec.end(), bottom.begin(), bottom.end());
	return concatenated_vec;
}

std::string hcat_frame_string(const std::string left, const std::string right,
		std::string::size_type max_left, std::string::size_type max_right) {
	return nullptr;
}

vec_str hcat(const vec_str& left, const vec_str& right) {
	vec_str concatenated_vec;
	if (left.empty() && right.empty()) {
		concatenated_vec.push_back(std::string("both left and right strings group is empty"));
		return concatenated_vec;
	}
	std::string::size_type max_left_padding = get_max_padding(left);
	std::string::size_type max_right_padding = get_max_padding(right);
	std::string border(std::string(max_left_padding + max_right_padding + 7, '*'));
	concatenated_vec.push_back(border);
	//std::transform(left.begin(), left.end(), right.begin(), right.end(), hcat_frame_string);
	//above would have worked if hcat_frame_string had only two parameters left and right
	/** learn to use transform(binary) with above hcat_frame_string function */
	for (vec_str::const_iterator lidx = left.begin(), ridx = right.begin();
			lidx != left.end() || ridx != right.end(); ++lidx, ++ridx) {
		if ((lidx != left.end()) && (ridx != right.end())) {
			std::string temp_str("* " + *lidx + std::string(max_left_padding - lidx->size() + 1, ' ') + '|');
			temp_str += (" " + *ridx + std::string(max_right_padding - ridx->size() + 1, ' ') + '*');
			concatenated_vec.push_back(temp_str);
			// now erasing is gonna cost more time or allocating and destroying temp_str everytime in loop ?
			//temp_str.erase(temp_str.begin(), temp_str.end());  // probably erasing everytime
		}
		// if right gets empty
		else if ((lidx != left.end())) {
			concatenated_vec.push_back(std::string("* " + *lidx + std::string(max_left_padding - lidx->size() + 1, ' ') + "| " +
						std::string(max_right_padding + 1, ' ') + '*'));
		}
		// if left gets empty
		else {
			concatenated_vec.push_back(std::string("* " + std::string(max_left_padding + 1, ' ') + "| "
						+ *ridx + std::string(max_right_padding - ridx->size() + 1, ' ') + '*'));
		}
	}
	concatenated_vec.push_back(border);
	return concatenated_vec;
}