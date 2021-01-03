// main file

#include "../inc/student_info.hpp"
#include "../inc/grade.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <list>

// change this typedef to change between vector or list
typedef std::list<Student_info> my_container;

std::list<Student_info> extract_fails(my_container& students);
void print_details(const my_container& students, std::string::size_type& max_length_padding);

int main(int argc, char **argv) {
	my_container students;
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
	//std::sort(students.begin(), students.end(), compare);  // can't use with list
	// list provides its own sorting method
	students.sort(compare);
	std::cout << std::endl << "Generating Report...\n" << std::endl;
	my_container failed_students = extract_fails(students);
	std::cout << "Students who passed: " << std::endl;
	print_details(students, max_length);
	std::cout << std::endl << "Students who failed: " << std::endl;
	print_details(failed_students, max_length);
	return 0;
}

my_container extract_fails(my_container& students) {
	my_container fail;
	my_container::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);  // returns just next iter to the deleted one
		}
		else {
			++iter;
		}
	}
	return fail;
}

void print_details(const my_container& students, std::string::size_type& max_length_padding) {
	for (my_container::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
		std::cout << iter->name  // it's same to (*iter).name
			<< std::string(max_length_padding - iter->name.size() + 1, ' ');
		try {
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << iter->total_grade << std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error de) {
			std::cout << de.what();
		}
	}
}