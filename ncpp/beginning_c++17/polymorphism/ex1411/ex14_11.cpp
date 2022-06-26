#include "box.hpp"                                 // For the Box class
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class
#include "vessel.hpp"
#include "can.hpp"

#include <iostream>
#include <vector>

int main(void) {
	Box box{ 40, 30, 20 };
	Can can{ 10, 3 };
	Carton carton{ 40, 30, 20, "plastic" };
	ToughPack hardcase{ 40, 20, 30 };

	std::vector<Vessel*> vessels{ &box, &can, &carton, &hardcase };

	for (const Vessel* vessel: vessels) {
		std::cout << "Volume is " << vessel->volume() << std::endl;
	}

	return 0;
}
