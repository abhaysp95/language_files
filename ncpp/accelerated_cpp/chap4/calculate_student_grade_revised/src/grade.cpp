// cpp file for "grade.hpp"

#include "../inc/grade.hpp"
#include "../inc/student_info.hpp"
#include "../inc/median.hpp"

#include <vector>

double grade(const Student_info& student) {
	return grade(student.midterm, student.final, student.homework);
}

double grade(const double& midterm, const double& final, const std::vector<double>& homework_grade) {
	double homework_median = median(homework_grade);
	return grade(midterm, final, homework_median);
}

double grade(const double& midterm, const double& final, double homework_median) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_median;
}

// write here