// cpp file for "student_info.hpp"

#include "../inc/student_info.hpp"
#include "../inc/grade.hpp"

#include <vector>
#include <string>
#include <limits>

bool compare(const Student_info& student1, const Student_info& student2) {
	return student1.name < student2.name;  // increasing order
}

std::istream& read_and_calculate_grade(std::istream& in, Student_info& student) {
	std::cout << "Enter the name of student: " << std::endl;
	double midterm{0.0}, final{0.0};
	in >> student.name;
	std::cout << "Enter the midterm and final marks of \"" << student.name << "\": " << std::endl;
	in >> midterm >> final;
	std::cout << "Enter the homework grades of \"" << student.name << "\"[press Ctrl-d to cancel]: " << std::endl;
	std::vector<double> homework{0};
	read_hw(in, homework);  // read student's homework grade
	student.final_grade = grade(midterm, final, homework);
return in;
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
	}
	return in;
}


// write here