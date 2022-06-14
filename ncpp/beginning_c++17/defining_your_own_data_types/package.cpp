#include "package.hpp"

Package::Package(SharedCuboid pC): pCuboid{pC}, pNext{nullptr}
{}

Package::~Package() {
	delete pNext;
}

SharedCuboid Package::getCuboid() const {
	return this->pCuboid;
}

Package *Package::getNext() {
	return this->pNext;
}

void Package::setNext(Package *pPackage) {
	this->pNext = pPackage;
}
