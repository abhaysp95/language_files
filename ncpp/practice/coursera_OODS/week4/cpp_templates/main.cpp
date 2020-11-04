#include <iostream>
#include "uiuc/cube.hpp"
//#include "template.hpp"

namespace tmax {
	template <typename T>
	T myMax(T a, T b) {
		return a > b ? a : b;
	}
};


int main(int argc, char **argv) {
	uiuc::Cube cube;
	cube.getVolume();
	uiuc::Cube cube1(5);
	cube1.getVolume();
	cube.getVolume(10);
	std::cout << "Max in (10, 20): " << tmax::myMax(10, 20) << std::endl;
	std::cout << "Max in ('p', 'l'): " << tmax::myMax('p', 'l') << std::endl;
	std::cout << "Max in (Ram, Shyam): " << tmax::myMax("Ram", "Shyam") << std::endl;  // comparision of address of Ram and Shyam
	std::cout << "Max in (Ram, Shyam): " << tmax::myMax(std::string("Ram"), std::string("Shyam")) << std::endl;  // actual comp. of string
	// compare Cubes here
	return 0;
}
