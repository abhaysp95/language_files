// main file

#include <iostream>
#include <stdexcept>  // standard exceptions of C++
#include <exception>

void stdf1() {
	int a = 10, b = 0;
	try {
		if (10 == a) {
			throw 10;
		}
		if (b == 0) {
			throw std::runtime_error("divide by zero error");
		}
		int c = a / b;
	}
	catch (std::runtime_error& error) {
		std::cout << "Exception:\n" << error.what() << std::endl;
	}
	catch (int& num) {
		std::cout << "Execption: " << num << std::endl;
	}
	catch (...) {
		std::cout << "All exception catch" << std::endl;
	}
	/* you can also have multiple catch blocks, like java and to catch all
	 * exceptions in one, use catch(...) */
}

int main(int argc, char **argv) {
    /* code here */
	int a = 10, b = 0;
	try {
		if (b == 0) {
			throw ("DivideByZeroException");
		}
		int res = a / b;
		std::cout << "result: " << res << std::endl;
	}
	catch (const char* ex) {
		std::cout << "Exception:" << std::endl << ex << std::endl;
	}
	stdf1();
    return 0;
}

/* standard exceptions of C++:
Exception:
- std::bad_alloc
- std::bad_cast
- std::logic_failure
  - std::domain_error
  - std::invalid_argument
  - std::length_error
  - std::out_of_range
- std::bad_typeid
- std::bad_exception
- std::runtime_error
  - std::overflow_error
  - std::range_error
  - std::underflow_error
*/