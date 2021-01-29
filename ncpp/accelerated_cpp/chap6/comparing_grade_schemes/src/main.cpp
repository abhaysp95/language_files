// main file

#include <iostream>
#include <algorithm>

#include "../inc/grade.hpp"
#include "../inc/median_avg.hpp"
#include "../inc/student_info.hpp"
#include "../inc/perform_analysis.hpp"

int main(int argc, char **argv) {
	// two types of students, one who did all his homework
	// and one who didn't
	std::vector<Student_info> did, did_not;
	Student_info student;
	// read all records, seperating them based on whether all homework was done
	while (read(std::cin, student)) {
		if (did_all_hw(student)) {
			did.push_back(student);
		}
		else {
			did_not.push_back(student);
		}
	}

	// check that both groups contain data
	if (did.empty()) {
		std::cout << "No student did the homework!" << "\n";
		return EXIT_FAILURE;
	}
	else if (did_not.empty()) {
		std::cout << "Every student did the homework!" << "\n";
		return EXIT_SUCCESS;
	}

	// do the analyses
	write_analysis(std::cout, "median", median_analysis, did, did_not);
	write_analysis(std::cout, "average", average_analysis, did, did_not);
	write_analysis(std::cout, "optimistic_median", optimistic_median_analysis, did, did_not);

	// do something for failed students
	std::vector<Student_info> failed;
	failed = extract_fails(did);  // only those who did there homeworks
	return 0;
}