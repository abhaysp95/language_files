// header file

#ifndef _GUARD_GRADE_HPP_
#define _GUARD_GRADE_HPP_

#include "../inc/student_info.hpp"

double grade(const Student_info& student);
double grade(const double& midterm, const double& final, const std::vector<double>& homework_grade);
double grade(const double& midterm, const double& final, double homework_median);

#endif