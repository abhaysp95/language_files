#include "truckload.hpp"

#include <iostream>

TruckLoad::TruckLoad(const std::vector<SharedCuboid>& cuboids) {
	for (const SharedCuboid& cuboid: cuboids) {
		addCuboid(cuboid);
	}
}

SharedCuboid TruckLoad::nullCuboid {};  // initialize static member of class

SharedCuboid TruckLoad::Iterator::getFirstCuboid() {
	pCurrent = pHead;
	return pCurrent ? pCurrent->pCuboid : nullptr;
}

SharedCuboid TruckLoad::Iterator::getNextCuboid() {
	if (!pCurrent) {
		return getFirstCuboid();
	}
	pCurrent = pCurrent->pNext;
	return pCurrent ? pCurrent->pCuboid : nullptr;
}

void TruckLoad::addCuboid(SharedCuboid cuboid) {
	Package* package = new Package{cuboid};
	if (pTail) {
		pTail->pNext = package;
		pTail = pTail->pNext;
	} else {
		pHead = package;
		pTail = package;
	}
}

bool TruckLoad::removeCuboid(SharedCuboid aCuboid) {
	Package* previous{nullptr};
	Package* current{pHead};

	while (current) {
		if (current->pCuboid == aCuboid) {
			if (previous) {
				previous->pNext =  current->pNext;
			} else {
				pHead = current->pNext;
			}
			current->pNext = nullptr;
			delete current;

			return true;
		}
		previous = current;
		current = current->pNext;
	}

	return false;
}

SharedCuboid& TruckLoad::operator[](size_t index) {
	size_t count{};
	/* TruckLoad::Iterator iter = this->getIterator();
	for (SharedCuboid cuboid = iter.getFirstCuboid(); cuboid; cuboid = iter.getNextCuboid()) {
		if (count++ == index) {
			return cuboid;
		}
	}

	return nullptr; */

	// can't use TruckLoad::Iterator if want to return reference to a cuboid to
	// modify the results from subscript operator
	for (Package *package{pHead}; package; package = package->pNext) {
		if (count++ == index) {
			return package->pCuboid;
		}
	}

	return nullCuboid;
}

std::ostream& operator<<(std::ostream& out, const TruckLoad& load) {
	size_t count{};
	TruckLoad::Iterator iter = load.getIterator();
	for (SharedCuboid cuboid = iter.getFirstCuboid(); cuboid; cuboid = iter.getNextCuboid()) {
		out << *cuboid;
		if (!(++count % 5)) {
			out << '\n';
		}
	}
	if (count % 5) {
		out << '\n';
	}

	return out;
}
