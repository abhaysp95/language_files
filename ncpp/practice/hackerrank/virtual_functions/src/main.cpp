// main file

#include <iostream>
#include "../inc/data.hpp"

int main(int argc, char **argv) {
	int n, val;
	std::cin >> n;  // number of object going to be created
	Person *per[n];

	for (int i = 0; i < n; ++i) {
		std::cin >> val;
		if (val == 1) {
			// val is 1, current object is of type Professor
			per[i] = new Professor;
		}
		else {
			// else the current object is going to be type of Student
			per[i] = new Student;
		}
		per[i]->getdata();  // get the data from the user
	}
	std::cout << "--------------" << std::endl;
	for (int i = 0; i <n; ++i) {
		per[i]->putdata();  // print the required output
	}
    return 0;
}