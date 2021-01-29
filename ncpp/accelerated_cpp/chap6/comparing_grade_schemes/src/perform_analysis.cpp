// cpp file for "perform_analysis.hpp"

#include "../inc/perform_analysis.hpp"
#include "../inc/student_info.hpp"
#include "../inc/grade.hpp"
#include "../inc/median_avg.hpp"

#include <algorithm>

double median_analysis(const std::vector<Student_info>& students) {
	std::vector<double> grades;
	std::transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const std::vector<Student_info>& students) {
	std::vector<double> grades;
	std::transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median_analysis(const std::vector<Student_info>& students) {
	std::vector<double> grades;
	std::transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(std::ostream& out, const std::string& name,
		double analysis(const std::vector<Student_info>&),
		const std::vector<Student_info>& did,
		const std::vector<Student_info>& did_not) {
	out << name << ": median(did) = " << analysis(did) << ", median(did_not) = " << analysis(did_not) << "\n";
}
