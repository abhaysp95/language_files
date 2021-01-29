// header file

#ifndef _GUARD_MEDIAN_AVG_HPP_
#define _GUARD_MEDIAN_AVG_HPP_

#include "../inc/student_info.hpp"
#include <vector>

double median(const std::vector<double>& vec);
double average(const std::vector<double>& vec);
double optimistic_median(const Student_info& s);

#endif