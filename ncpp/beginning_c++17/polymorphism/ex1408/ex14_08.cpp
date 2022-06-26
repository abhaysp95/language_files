// Calling virtual functions from constructors and destructors

#include "box.hpp"                                 // For the Box class
#include "toughpack.hpp"                           // For the ToughPack class

#include <iostream>
#include <typeinfo>  // for std::type_info


#define SEP "--------------"

int main(void) {
	ToughPack toughpack{ 1.0, 2.0, 3.0 };
	toughpack.showVolume();

	return 0;
}

