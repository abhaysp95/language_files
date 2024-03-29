#include "box.hpp"                                 // For the Box class
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

#include <iostream>
#include <vector>
#include <memory>

#define SEP "--------------"

int main(void) {
	// Careful: this first attempt at a mixed collection is a bad idea (object slicing!)
	std::vector<Box> boxes;
	boxes.push_back(Box{20.0, 30.0, 40.0});
	boxes.push_back(ToughPack{20.0, 30.0, 40.0});
	boxes.push_back(Carton{20.0, 30.0, 40.0, "plastic"});

	for (const auto& p : boxes)
		p.showVolume();

	std::cout << SEP << std::endl;

	// Next, we create a proper polymorphic vector<>:
	std::vector<std::unique_ptr<Box>> polymorphicBoxes;
	polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
	polymorphicBoxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
	polymorphicBoxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0, "plastic"));

	for (const auto& p : polymorphicBoxes)
		p->showVolume();
}
