// Imagine a course in which each student's final exam counts for 40% of the
// final grade, the midterm exam counts for 20%, and the average homework grade
// makes up the remaining 40%




// main file

#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
	std::cout << "Enter you midterm and final term marks: ";
	double final{0}, midterm{0};
	std::cin >> midterm >> final;
	std::cout << "Enter all your homework grades(followed by eof): " << std::endl;
	std::vector<double> homework;
	double x{0};
	while (std::cin >> x) {
		homework.push_back(x);
	}
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		std::cout << "Enter some homework numbers" << std::endl;
		return 1;
	}
	std::sort(homework.begin(), homework.end()); // n(log(n))
	vec_sz mid = size / 2;
	double median = mid % 2 != 0 ? (homework.at(mid) + homework.at(mid - 1)) / 2 : homework.at(mid);
	std::streamsize prec = std::cout.precision();
	std::cout << "Your final grade is " << std::setprecision(3)
		<< midterm * 0.2 + final * 0.4 + median * 0.4
		<< std::setprecision(prec) << std::endl;
	return 0;
}