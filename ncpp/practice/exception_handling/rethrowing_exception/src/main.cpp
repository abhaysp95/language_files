// main file

#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {
	try {
		try {
			//throw "don't do it";
			const char* e[2] = {"this is bad", "very very bad"};
		}
		catch (const char* e) {
			std::cout << "charater type in inner block --> " << e << std::endl;
			throw;  // this will throw the caught exception again
			/* you can just as well specify the type of thrown exception from here, like
			   throw runtime_error("runtime error"); */
		}
		catch (const char** e) {
			std::cout << "in here" << std::endl;
			throw;
		}
	}
	catch (const char* e) {
		std::cout << "charater type in outer block --> " << e << std::endl;
	}
	catch (const char** e) {
		std::cout << "charater type in outer block --> " << e << std::endl;
		for (int i = 0; i < 2; ++i) {
			std::cout << *e << std::endl;
		}
	}
	catch (...) {
		std::cout << "any type in outer block --> " << std::endl;
	}
    return 0;
}