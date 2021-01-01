// main file

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>

double grade(double midterm, double final, const std::vector<double>& homework);
double grade(double midterm, double final, double homework);
double median(std::vector<double> vec);
std::istream& read_hw(std::istream& in, std::vector<double>& homework);

double median(std::vector<double> vec) {
	typedef std::vector<double>::size_type vc_size;
	vc_size vector_size = vec.size();
	vc_size mid = vector_size / 2;
	std::sort(vec.begin(), vec.end());
	return (vector_size % 2 == 0) ? (vec.at(mid) + vec.at(mid - 1)) / 2 : vec.at(mid);
}

double grade(double midterm, double final, double hw_grade) {
	return 0.2 * midterm + 0.4 * final + 0.4 * hw_grade;
}

double grade(double midterm, double final, const std::vector<double>& homework) {
	if (homework.size() == 0) {
		throw std::domain_error("student has done no homework");
	}
	return grade(midterm, final, median(homework));
}

std::istream& read_hw(std::istream& in, std::vector<double>& homework) {
	if (in) {
		homework.clear();
		double mark;
		while (in >> mark) {
			homework.push_back(mark);
		}
		in.clear();
	}
	return in;
}

int main(int argc, char **argv) {
	std::cout << "Please enter you name here: " << std::endl;
	std::string name;
	std::cin >> name;
	std::cout << "Enter your midterm and final grade(in sequence): " << std::endl;
	double midterm{0}, final{0};
	std::cin >> midterm >> final;
	std::cout << "Enter your homework grade here[press Ctrl-d to cancel]: " << std::endl;
	std::vector<double> hw_grade;
	read_hw(std::cin, hw_grade);
	try {
		// not good idea, cause say, if grade throws an exception then 'Final
		// result: ' may get printed and output stream's precision may get to
		// set to 3
		//std::cout << "Final result: " << std::setprecision(3) << grade(midterm, final, hw_grade)
			//<< std::setprecision(prec) << std::endl;

		// ensure that call to grade happens successfully and then print
		const double result = grade(midterm, final, hw_grade);
		std::streamsize prec = std::cout.precision();
		std::cout << "Final result: " << std::setprecision(3) << result
			<< std::setprecision(prec) << std::endl;
	}
	catch (std::domain_error) {
		std::cout << std::endl << "You must enter your grades, try again" << std::endl;
		return 1;
	}
	return 0;
}