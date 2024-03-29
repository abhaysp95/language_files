// cpp file for "student_info.hpp"

#include "../inc/student_info.hpp"

#include <vector>
#include <string>
#include <limits>

bool compare(const Student_info& student1, const Student_info& student2) {
	return student1.name < student2.name;  // increasing order
}

std::istream& read(std::istream& is, Student_info& student) {
	std::cout << "Enter the name of student: " << std::endl;
	is >> student.name;
	std::cout << "Enter the midterm and final marks of \"" << student.name << "\": " << std::endl;
	is >> student.midterm >> student.final;
	std::cout << "Enter the homework grades of \"" << student.name << "\"[press Ctrl-d to cancel]: " << std::endl;
	read_hw(is, student.homework);  // read student's homework grade
	return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& homework_grade) {
	if (in) {
		std::cout << "in successful" << std::endl;
		homework_grade.clear();
		double grade;
		while (in >> grade) {
			homework_grade.push_back(grade);
		}
		// clear error flag
		in.clear();  // clear the stream for input of next student
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear of wrong input
		/** just some checking
		if (in) {
			int x;
			in >> x;
			std::cout << "in successful again: " << x << std::endl;
		}
		else {
			std::cout << "in failed" << std::endl;
		} */
	}
	return in;
}


// write here