// cpp file for "grade.hpp"

#include "../inc/grade.hpp"
#include "../inc/median_avg.hpp"

#include <stdexcept>

double grade(const Student_info& student) {
	return grade(student.midterm, student.final, student.homework);
}

double grade(const double& midterm, const double& final, const std::vector<double>& homework_grade) {
	double homework_median = median(homework_grade);
	return grade(midterm, final, homework_median);
	/*double homework_sum{};
	for (const double& num: homework_grade) {
		homework_sum += num;
	}
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_sum;*/
}

double grade(const double& midterm, const double& final, double homework_median) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_median;
}

/** this function will takes student_info type and perform grade() operation */
double grade_aux(const Student_info& s) {
	try {
		return grade(s);
	}catch(std::domain_error) {
		// no homework submitted
		return grade(s.midterm, s.final, 0);
	}
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}