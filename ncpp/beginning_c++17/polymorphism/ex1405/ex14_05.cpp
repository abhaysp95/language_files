#include "box.hpp"                                 // For the Box class

#include <iostream>
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

// because parameter is reference to virutal class, compiler arranges dynamic
// binding
void show_volume(const Box& box) {
	std::cout << "Box usable volume is: " << box.volume() << std::endl;
}

int main(void) {
	Box box {20.0, 30.0, 40.0};
	ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
	Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

	show_volume(box);
	show_volume(hardcase);
	show_volume(carton);
}
