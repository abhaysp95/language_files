// main file

#include "../inc/student_info.hpp"
#include "../inc/grade.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

std::vector<Student_info> extract_fails(std::vector<Student_info>& students);
void print_details(const std::vector<Student_info>& students, std::string::size_type& max_length_padding);

int main(int argc, char **argv) {
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type max_length = 0;
	while (read(std::cin, record)) {
		// max requires same type of argument(both are of string::size_type)
		max_length = std::max(max_length, record.name.size());
		if (std::cin.eof()) {  // check if eofbit is true
			students.push_back(record);
		}
	}
	// alphabetize the records
	std::sort(students.begin(), students.end(), compare);
	std::cout << std::endl << "Generating Report...\n" << std::endl;
	std::vector<Student_info> failed_students = extract_fails(students);
	std::cout << "Students who passed: " << std::endl;
	print_details(students, max_length);
	std::cout << std::endl << "Students who failed: " << std::endl;
	print_details(failed_students, max_length);
	return 0;
}

// seperate passing and failing student records
// second attempt: correct but also slow
std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
	std::vector<Student_info> fail;
	std::vector<Student_info>::size_type count{};
	while (count != students.size()) {  // overhead for calling 'size()' each time is negligible
		if (fgrade(students.at(count))) {
			fail.push_back(students.at(count));
			// instead of making a second vector which contains the pass students
			// delete the failed ones from parameter's vector, as the failed ones
			// are already been added to fail vector
			students.erase(students.begin() + count);
		}
		else {
			count++;
		}
	}
	return fail;
}

void print_details(const std::vector<Student_info>& students, std::string::size_type& max_length_padding) {
	for (std::vector<Student_info>::size_type i = 0; i < students.size(); ++i) {
		std::cout << students.at(i).name
			<< std::string(max_length_padding - students.at(i).name.size() + 1, ' ');
		try {
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << students.at(i).total_grade << std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error de) {
			std::cout << de.what();
		}
	}
}