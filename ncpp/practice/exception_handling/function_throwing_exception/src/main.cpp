// main file

#include <iostream>
#include <stdexcept>

/* you can't just use throw() here and think that'll it'll tell the calling
 * function that this function can throw anytype of exception */
void test() throw(int, const char*, std::runtime_error) {
	//throw 10;
	//throw "Not good";
	throw std::runtime_error("what the heck");
}

int main(int argc, char **argv) {
	try {
		test();
	}
	catch (int e) {
		std::cout << "integer type: " << e << std::endl;
	}
	catch (const char* e) {
		std::cout << "const char* type: " << e << std::endl;
	}
	catch (std::runtime_error e) {
		std::cout << "runtime_error type: " << e.what() << std::endl;
	}
    return 0;
}