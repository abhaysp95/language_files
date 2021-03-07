// main file

#include <iostream>
#include <vector>

#include "../inc/shape.hpp"

void rotate_all(std::vector<Shape*>& v, int angle) {
	for (Shape* const p: v) {
		p->rotate(angle);
	}
}

int main(int argc, char **argv) {
	/* code here */
	return 0;
}