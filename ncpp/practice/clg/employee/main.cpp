#include <iostream>
#include <cstring>

class Employee {
	public:
		char name[20];
		int emp_code;

		void set_emp(const char *n, int c) {
			strcpy(name, n);
			emp_code=c;
		}
		void get_emp() {
			std::cout << name << std::endl;
			std::cout << emp_code << std::endl;
		}
};

int main(int argc, char **argv) {
	Employee emp1;
	emp1.set_emp("Vijay", 1);
	emp1.get_emp();
	return 0;
}
