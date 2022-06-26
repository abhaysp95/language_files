#include "box.hpp"                                 // For the Box class
#include "cerealpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

#include <iostream>
#include <vector>
#include <memory>

#define SEP "--------------"

int main(void) {
	Box* pBox{ new Box(10.0, 20.0, 30.0) };
	pBox->showVolume();

	// pBox->surface();  // uncomment for error
	// std::cout << "surface: " << dynamic_cast<Carton*>(pBox)->surface() << std::endl;

	// you need to be sure that pBox is pointing to Carton type object of
	// object which have Carton as it's base to call non-virtual
	// Carton::surface() method

	Carton* pCarton{ dynamic_cast<Carton*>(pBox) };
	if (pCarton) {
		std::cout << "suface(downcasting worked): " << pCarton->surface() << std::endl;
	} else {
		std::cout << "pCarton is nullptr(downcasting didn't work)" << std::endl;
	}

	Box* pBox2{ new CerealPack(10.0, 20.0, 30.0, "plastic", "good") };

	Carton* pCarton2{ dynamic_cast<Carton*>(pBox2) };
	if (pCarton2) {
		std::cout << "surface(upcasting worked): " << pCarton2->surface() << std::endl;
	} else {
		std::cout << "pCarton is nullptr(downcasting didn't work)" << std::endl;
	}

	return 0;
}
