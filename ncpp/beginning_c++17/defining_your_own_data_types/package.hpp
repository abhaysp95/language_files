#ifndef _PACKAGEG_HPP
#define _PACKAGEG_HPP

#include "cuboid.hpp"
#include <iostream>
#include <memory>

using SharedCuboid = std::shared_ptr<Cuboid>;

class Package {
	private:
		SharedCuboid pCuboid;  // pointer to the Cuboid object contained in this Package
		Package *pNext;  // pointer to the next Package in the list
		// you can very well use std::unique_ptr<Package> for pNext (this is
		// just to show usage of destructor)

	public:
		Package(SharedCuboid pC);
		~Package();

		// retrieve the Cuboid pointer
		SharedCuboid getCuboid() const;

		// retrieve or update the pointer to the next Package
		Package *getNext();
		void setNext(Package *pPackage);
};

#endif
