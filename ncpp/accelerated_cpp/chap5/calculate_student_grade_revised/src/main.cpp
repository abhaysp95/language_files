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

//std::vector<Student_info> extract_fails(std::vector<Student_info>& students);
std::list<Student_info> extract_fails(std::list<Student_info>& students);
void print_details(const std::vector<Student_info>& students, std::string::size_type& max_length_padding);
void print_details(const std::list<Student_info>& students, std::string::size_type& max_length_padding);

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
	// change is made here, created a list from vector                             <------ change
	std::list<Student_info> students_list(students.begin(), students.end());
	std::list<Student_info> failed_students = extract_fails(students_list);
	std::cout << "Students who passed: " << std::endl;
	print_details(students, max_length);
	std::cout << std::endl << "Students who failed: " << std::endl;
	print_details(failed_students, max_length);
	return 0;
}

// seperate passing and failing student records
// fourth attempt: using list instead of vector
// list is much faster for insertion and deletion operation anywhere randomly
// from the list when comparing to vector, whereas vector is much faster for
// fast random access, so if container grow or shrinks just from end, vector
// will be much faster, so vector outgrow list if accessed sequentially
std::list<Student_info> extract_fails(std::list<Student_info>& students) {
	std::list<Student_info> fail;
	std::list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
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

void print_details(const std::list<Student_info>& students, std::string::size_type& max_length_padding) {
	//for (std::list<Student_info>::size_type i = 0; i < students.size(); ++i) {
	for (std::list<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
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


/**
  list don't invalidate whole iterator when one of the element pointed by iter
  is being deleted, only the iter which points to element being deleted is
  being invalid, while vector invalidates whole iter when 'push_back()' or
  'erase()' happens. Consisting of this reason storing std::vector<_Tp>'s end()
  is a bad idea
  */