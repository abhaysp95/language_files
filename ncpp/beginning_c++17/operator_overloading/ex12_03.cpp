#include "box.hpp"

#include <iostream>
#include <ostream>
#include <vector>
#include <utility>

// defines operator <=, >, >=, != operators for any type T in terms of T's <
// and == operator
using namespace std::rel_ops;

void show(const Box& box1, std::string_view relationship, const Box& box2)
{
	std::cout << "Box " << box1.getLength() << 'x' << box1.getWidth() << 'x' << box1.getHeight()
		<< relationship
		<< "Box " << box2.getLength() << 'x' << box2.getWidth() << 'x' << box2.getHeight()
		<< std::endl;
}
int main(void) {
	const std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
		Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
	const Box theBox {3.0, 1.0, 3.0};
	for (const auto& box : boxes) {
		if (theBox > box) {
			show(theBox, " is greater than ", box);
		}
	}
	std::cout << std::endl;
	for (const auto& box : boxes) {
		if (theBox != box) {
			show(theBox, " is not equal to ", box);
		}
	}
	std::cout << std::endl;
	for (size_t i {}; i < boxes.size() - 1; ++i) {
		for (size_t j {i+1}; j < boxes.size(); ++j) {
			if (boxes[i] <= boxes[j]) {
				show(boxes[i], " less than or equal to ", boxes[j]);
			}
		}
	}

	// just a check (from next section)
	std::ostream &out = std::cout;
	std::operator<<(out, "how are you?\n");  // working
}
