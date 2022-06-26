#include "box.hpp"                                 // For the Box class
#include "cerealpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

#include <iostream>
#include <vector>
#include <memory>

#define SEP "--------------"

void doThat(Box& rBox) {
	rBox.showVolume();

	// from Box to Carton
	/** This statement casts from type reference to Box to type reference to
	 * Carton. Of course, it’s possible that the object passed as an argument
	 * may not be a Carton object, and if this is the case, the cast won’t
	 * succeed. There is no such thing as a null reference, so this fails in a
	 * different way from a failed pointer cast. Execution of the function
	 * stops, and an exception of type std:bad_cast is thrown */
	// Carton& rCarton{ dynamic_cast<Carton&>(rBox) };
	// rCarton.showVolume();

	/** So, applying a dynamic cast to a reference blind is obviously risky,
	 * but there’s an easy alternative */
	// so, first check
	Carton* rCarton{ dynamic_cast<Carton*>(&rBox) };
	if (rCarton) {
		rCarton->showVolume();
	}
}

int main(void) {
	Box pBox0{ 1.0, 2.0, 3.0 };
	// doThat(pBox0);

	Box* pBox1{ new Box(10.0, 20.0, 30.0) };
	// doThat(*pBox);

	// doThat(*dynamic_cast<Carton*>(pBox1));

	std::cout << SEP << std::endl;

	Carton pCarton0{ 1.0, 2.0, 3.0, "plastic" };
	doThat(pCarton0);

	std::cout << SEP << std::endl;

	Carton* pCarton1{ new Carton(10.0, 20.0, 30.0, "metal") };
	doThat(*pCarton1);

	std::cout << SEP << std::endl;

	pBox1 = pCarton1;
	doThat(*pBox1);

	std::cout << SEP << std::endl;

	Box* pBox2{ dynamic_cast<Box*>(pCarton1) };
	doThat(*pBox2);

	std::cout << SEP << std::endl;

	CerealPack* pPack{ new CerealPack(100, 200, 300, "gold", "good") };
	doThat(*dynamic_cast<Carton*>(pPack));
	doThat(*dynamic_cast<Box*>(pPack));

	std::cout << SEP << std::endl;

	return 0;
}
