#include "box.hpp"                                 // For the Box class

#include <iostream>
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

int main(void) {
	Box box {20.0, 30.0, 40.0};
	ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
	Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

	box.showVolume();                              // Volume of Box
	hardcase.showVolume();                         // Volume of ToughPack
	carton.showVolume();                           // Volume of Carton
	std::cout << "hardcase volume is " << hardcase.volume() << std::endl;

	// Now  using a base pointer...
	Box* pBox {&box};                              // Points to type Box
	std::cout << "\nbox volume through pBox is " << pBox->volume() << std::endl;
	pBox->showVolume();

	pBox = &hardcase;                             // Points to type ToughPack
	std::cout << "hardcase volume through pBox is " << pBox->volume() << std::endl;
	pBox->showVolume();

	pBox = &carton;                              // Points to type Carton
	std::cout << "carton volume through pBox is " << pBox->volume() << std::endl;
	pBox->showVolume();
}

// default parameter values are not used from derived class but from base (as
// shown above in call resovled dynamically), only exception is shown
// hardcase.volume() where call is resolved statically
