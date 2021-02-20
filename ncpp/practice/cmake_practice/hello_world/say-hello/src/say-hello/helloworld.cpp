#include "helloworld.hpp"

void hello::say_hello() {
	std::cout << "this is hello from say_hello from header file, version: " << SAY_HELLO_VERSION << std::endl;
}
