#include <iostream>

// since this also inherited the include-directories of the library to the path to header(library) now will be
#include <say-hello/helloworld.hpp>

int main(int argc, char **argv) {
	hello::say_hello();
	// main can also get the pre-processor definition from CMakeLists of the library
	std::cout << "This is version: " << SAY_HELLO_VERSION << std::endl;
	return 0;
}
