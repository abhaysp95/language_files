// main file

#include "../inc/student_info.hpp"
#include "../inc/grade.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

int main(int argc, char **argv) {
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type max_length = 0;
	while (read_and_calculate_grade(std::cin, record)) {
		max_length = std::max(max_length, record.name.size());
		students.push_back(record);
	}
	// alphabetize the records
	std::sort(students.begin(), students.end(), compare);
	for (std::vector<Student_info>::size_type i = 0; i < students.size(); ++i) {
		std::cout << students.at(i).name
			<< std::string(max_length - students.at(i).name.size() + 1, ' ');
		try {
			//const double result = grade(students.at(i));
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << students.at(i).final_grade << std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error de) {
			std::cout << de.what();
		}
		std::cout << std::endl;
	}
	return 0;
}