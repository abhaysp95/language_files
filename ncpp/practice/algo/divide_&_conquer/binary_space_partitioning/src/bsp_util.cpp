// cpp file for "bsp_util.hpp"

#include "../inc/bsp_util.hpp"

size_t get_place(std::string::const_iterator& begin, const std::string::const_iterator& end,
		size_t beg_place, size_t end_place) {
	size_t mid_place = (beg_place + end_place) / 2;
	if (begin != end) {
		if (*begin == 'F') {
			begin++;
			mid_place = get_place(begin, end, beg_place, mid_place);
		}
		else if (*begin == 'B') {
			begin++;
			mid_place = get_place(begin, end, mid_place + 1, end_place);
		}
	}
	return mid_place;
}