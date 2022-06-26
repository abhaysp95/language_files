#include "box.hpp"                                 // For the Box class
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

#include <iostream>
#include <vector>
#include <memory>

int main(void) {
	// beware of object slicing in this method
	std::vector<Box> boxes{};
	boxes.push_back(Box{20.0, 30.0, 40.0});
	boxes.push_back(ToughPack{20.0, 30.0, 40.0});
	boxes.push_back(Carton{20.0, 30.0, 40.0, "plastic"});

	for (const auto& box: boxes) {
		box.showVolume();
	}

	// need explaination for this one
	std::vector<std::unique_ptr<Box>> exp_boxes{};
	exp_boxes.push_back(std::make_unique<Box>(Box{20.0, 30.0, 40.0}));
	exp_boxes.push_back(std::make_unique<Box>(ToughPack{20.0, 30.0, 40.0}));
	exp_boxes.push_back(std::make_unique<Box>(Carton{20.0, 30.0, 40.0, "plastic"}));

	for (const auto& box: exp_boxes) {
		box->showVolume();
	}

	std::vector<std::unique_ptr<Box>> polymorphic_boxes{};
	polymorphic_boxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
	polymorphic_boxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
	polymorphic_boxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0, "plastic"));

	for (const auto& box: polymorphic_boxes) {
		box->showVolume();
	}

	return 0;
}
