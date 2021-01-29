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

/** function for exercise6 */
double all_three_analysis(const std::vector<Student_info>& students, const std::string& name) {
	std::vector<double> grades;
	if (name.compare("median") == 0) {
		std::transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	}
	else if (name.compare("average") == 0) {
		std::transform(students.begin(), students.end(), back_inserter(grades), average);
	}
	else if (name.compare("optimistic_median") == 0) {
		std::transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	}
	else {
		return EXIT_FAILURE;
	}
	return median(grades);
}

/** change made in function definition */
void write_analysis(std::ostream& out, const std::string& name,
		double analysis(const std::vector<Student_info>&, const std::string& name),
		const std::vector<Student_info>& did,
		const std::vector<Student_info>& did_not) {
	out << name << ": median(did) = " << analysis(did, name) << ", median(did_not) = " << analysis(did_not, name) << "\n";
}
