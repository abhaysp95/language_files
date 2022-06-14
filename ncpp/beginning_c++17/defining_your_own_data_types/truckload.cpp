#include "truckload.hpp"

TruckLoad::TruckLoad(const std::vector<SharedCuboid> &cuboids) {
	for (const auto& pCuboid: cuboids)
		this->addCuboid(pCuboid);
}

TruckLoad::TruckLoad(const TruckLoad &src) {
	for (Package *package{src.pHead}; package; package = package->getNext()) {
		this->addCuboid(package->getCuboid());
	}
}

TruckLoad::~TruckLoad() {
	delete this->pHead;
}

void TruckLoad::listCuboid() const {
	const size_t cuboidsPerLine = 5;
	size_t count {};
	Package *currentPackage {this->pHead};
	while (currentPackage) {
		currentPackage->getCuboid()->listCuboid();
		if (!(++count % cuboidsPerLine)) std::cout << std::endl;
		currentPackage = currentPackage->getNext();
	}
	if (count % cuboidsPerLine) std::cout << std::endl;
}

SharedCuboid TruckLoad::getFirstCuboid() {
	// return pCuboid's cuboid, if list is empty (return nullptr)
	pCurrent = pHead;
	return pCurrent ? pCurrent->getCuboid() : nullptr;
}

SharedCuboid TruckLoad::getNextCuboid() {
	if (!this->pCurrent)
		return this->getFirstCuboid();
	pCurrent = pCurrent->getNext();
	return pCurrent ? pCurrent->getCuboid() : nullptr;
}

void TruckLoad::addCuboid(SharedCuboid cuboid) {
	Package *pPackage = new Package {cuboid};
	if (this->pTail) {
		pTail->setNext(pPackage);
	} else {
		pHead = pPackage;
	}
	pTail = pPackage;
}

bool TruckLoad::removeCuboid(SharedCuboid cuboid) {
	Package *previous {nullptr};
	Package *current {pHead};

	while (current) {
		if (current->getCuboid() == cuboid) {
			if (previous) {
				previous->setNext(current->getNext());
			} else {
				pHead = current->getNext();
			}
			current->setNext(nullptr);
			delete current;

			return true;
		}
		previous = current;
		current = current->getNext();
	}

	return false;
}
