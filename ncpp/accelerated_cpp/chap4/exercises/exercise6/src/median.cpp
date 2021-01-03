// cpp file for "median.hpp"

#include "../inc/median.hpp"

#include <vector>
#include <stdexcept>
#include <algorithm>

double median(std::vector<double> vec) {
	typedef std::vector<double>::size_type vec_size;
	vec_size size = vec.size();
	if (size == 0) {
		throw std::domain_error("Vector is empty to find median");
	}
	sort(vec.begin(), vec.end());
	vec_size mid = size / 2;
	return size % 2 == 0 ? (vec.at(mid) + vec.at(mid - 1)) / 2 : vec.at(mid);
}