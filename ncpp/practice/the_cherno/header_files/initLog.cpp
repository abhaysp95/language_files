#include <iostream>
#include "log.hpp"

void log(const char* msg) {
	std::cout << msg << std::endl;
}

void initLog() {
	log("Initial log");
}
