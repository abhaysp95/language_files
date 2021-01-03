// cpp file for "student_info.hpp"

#include "../inc/student_info.hpp"

#include <vector>
#include <string>
#include <limits>
#include <ios>

bool compare(const Student_info& student1, const Student_info& student2) {
	return student1.name < student2.name;  // increasing order
}

std::istream& read(std::istream& is, Student_info& student) {
	std::cout << "Enter the name of student[or type 'quit/Quit' to quit entry]: " << std::endl;
	std::string entry_either_name_or_quit;
	is >> entry_either_name_or_quit;
	if (entry_either_name_or_quit != "quit" && entry_either_name_or_quit != "Quit") {
		student.name = entry_either_name_or_quit;  // cause this is name
		if (is) {
			std::cout << "Enter the midterm and final marks of \"" << student.name << "\": "
				<< std::endl;
			is >> student.midterm >> student.final;
			std::cout << "Enter the homework grades of \"" << student.name
				<< "\"[press 'q/Q' to cancel]: " << std::endl;
			read_hw(is, student.homework);  // read student's homework grade
		}  // don't clear the is, or else loop in the main.cpp will not end
	}
	else {  // user enter 'quit/Quit', set istream state flag to eofbit
		is.setstate(std::ios::eofbit);
	}
	// how to make std::cin errorflag to EOF ?
	return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& homework_grade) {
	if (in) {
		homework_grade.clear();
		std::string grade;
		while (true) {
			std::cin >> grade;
			if (grade == "q" || grade == "Q") {
				break;
			}
			double grade_double = atoi(grade.c_str());
			homework_grade.push_back(grade_double);
		}
		// clear error flag
		in.clear();  // clear the stream for input of next student
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear of wrong input
	}
	return in;
}


// write here