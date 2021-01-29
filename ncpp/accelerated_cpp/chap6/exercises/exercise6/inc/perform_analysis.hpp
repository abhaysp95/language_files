#ifndef _PERFORM_ANALYSIS_HPP_
#define _PERFORM_ANALYSIS_HPP_

#include <vector>

#include "../inc/student_info.hpp"

// perform median analysis
double median_analysis(const std::vector<Student_info>& students);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median_analysis(const std::vector<Student_info>& students);
double all_three_analysis(const std::vector<Student_info>& students, const std::string& name);
void write_analysis(std::ostream& out, const std::string& name,
		double analysis(const std::vector<Student_info>&, const std::string& name),
		const std::vector<Student_info>& did,
		const std::vector<Student_info>& did_not);

#endif
