// Imagine a course in which each student's final exam counts for 40% of the
// final grade, the midterm exam counts for 20%, and the average homework grade
// makes up the remaining 40%




// main file

#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

int main(int argc, char **argv) {
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
	std::cout << "Enter you midterm and final term marks: ";
	double final{0}, midterm{0};
	std::cin >> midterm >> final;
	std::cout << "Enter all your homework grades(followed by eof): " << std::endl;
	int count{0};
	double x{0}, sum{0};
	while (std::cin >> x) {
		sum += x;
		++count;
	}
	// get current precision
	std::streamsize prec = std::cout.precision();
	std::cout << "Your final grade is: " << std::setprecision(3)
		<< (midterm * 0.2 + final * 0.4 + sum * 0.4) / count
		<< std::setprecision(prec) << std::endl;
	return 0;
}