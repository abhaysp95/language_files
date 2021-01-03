// header file

#ifndef _GUARD_STUDENT_INFO_HPP_
#define _GUARD_STUDENT_INFO_HPP_

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info& student1, const Student_info& student2);
std::istream& read(std::istream& in, Student_info& student);
std::istream& read_hw(std::istream& in, std::vector<double>& homework_grade);

#endif