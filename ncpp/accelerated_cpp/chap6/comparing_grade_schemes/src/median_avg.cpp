// cpp file for "median_avg.hpp"

#include "../inc/median_avg.hpp"
#include "../inc/grade.hpp"

#include <stdexcept>
#include <algorithm>
#include <numeric>  // accumulate()

double median(const std::vector<double>& vec) {
	typedef std::vector<double>::size_type vec_size;
	vec_size size = vec.size();
	if (size == 0) {
		throw std::domain_error("Vector is empty to find median");
	}
	sort(vec.begin(), vec.end());
	vec_size mid = size / 2;
	return size % 2 == 0 ? (vec.at(mid) + vec.at(mid - 1)) / 2 : vec.at(mid);
}

double average(const std::vector<double>& vec) {
	/**
	  accumulate function adds the values in the range denoted by its first
	  two arguments, starting the summation with the value given by its
	  third argument
	  */
	return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

double optimistic_median(const Student_info& s) {
	std::vector<double> nonzero;
	/**
	  remove_copy is also a generic way to do remove and copy it takes three
	  iterators, first two denotes the sequence for source and third one is
	  destination. remove_copy() algorithm assumes that there is enough space
	  in the destination to hold all the elements that are copied.
	  back_inserter make nonzero grow as needed. fourth argument is the element
	  which we match with elements of sequence, if match found then the item is
	  removed from sequence. Items not matched are copied to destination
	  */
	std::remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	if (nonzero.empty()) {
		return grade(s.midterm, s.final, 0);
	}
	else {
		return grade(s.midterm, s.final, median(nonzero));
	}
}