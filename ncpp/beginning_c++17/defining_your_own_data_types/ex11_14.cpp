#include "package.hpp"
#include "truckload.hpp"

#include <ctime>
#include <cstdlib>

inline unsigned random(size_t count) {
	return 1 + static_cast<unsigned>(std::rand() / (RAND_MAX / count + 1));
}

inline SharedCuboid randomCuboid() {
	const size_t dimLimit {99};
	return std::make_shared<Cuboid>(random(dimLimit), random(dimLimit), random(dimLimit));
}

int main(void) {
	// initialize the random number generator
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	TruckLoad load1 {};
	const size_t cuboidCount {12};
	for (size_t i {}; i < cuboidCount; ++i) {
		load1.addCuboid(randomCuboid());
	}

	std::cout << "The first list:\n";
	load1.listCuboid();

	TruckLoad copy {load1};
	std::cout << "The copied truckload:\n";
	copy.listCuboid();

	// find the largest cuboid in list
	SharedCuboid largest {load1.getFirstCuboid()};
	SharedCuboid next {load1.getNextCuboid()};
	while (next) {
		if (next->compare(*largest)) {
			largest = next;
		}
		next = load1.getNextCuboid();
	}

	std::cout << "The largest cuboid is first list is: ";
	largest->listCuboid();
	std::cout << std::endl;

	load1.removeCuboid(largest);
	std::cout << "After removing the largest: \n";
	load1.listCuboid();

	const size_t nCount = 20;
	std::vector<SharedCuboid> cuboids;

	for (size_t i {}; i < nCount; ++i) {
		cuboids.push_back(randomCuboid());
	}

	TruckLoad load2 {cuboids};
	std::cout << "The second list is: \n";
	load2.listCuboid();

	SharedCuboid smallest {load2.getFirstCuboid()};
	for (SharedCuboid next = load2.getNextCuboid(); next; next = load2.getNextCuboid()) {
		if (smallest->compare(*next)) {
			smallest = next;
		}
	}

	std::cout << "Smallest box in second list: ";
	smallest->listCuboid();
	std::cout << std::endl;
}
