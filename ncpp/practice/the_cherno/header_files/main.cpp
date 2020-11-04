#include "common.hpp"
#include "log.hpp"

int main(int argc, char **argv) {
	initLog();
	log("This is main");
	return 0;
}
