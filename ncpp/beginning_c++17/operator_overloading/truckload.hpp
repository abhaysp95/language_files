#ifndef _TRUCKLOADV2_HPP
#define _TRUCKLOADV2_HPP

#include "cuboid.hpp"

#include <memory>
#include <vector>

using SharedCuboid = std::shared_ptr<Cuboid>;

class TruckLoad {
	private:
		class Package {
			public:
				SharedCuboid pCuboid;
				Package *pNext;
				Package(SharedCuboid aCuboid):
					pCuboid{aCuboid}, pNext{nullptr} {}
				~Package() { delete pNext; }  // delete with nullptr does nothing
		};

		Package *pHead {};
		Package *pTail {};

		// don't use this (unless you know the consequences, which is,
		// non-const reference to nullCuboid which can be used in all sorts of
		// wrong way)
		static SharedCuboid nullCuboid;  // pointer to nullptr

	public:
		class Iterator {
			private:
				Package *pHead {};
				Package *pCurrent {};

				friend class TruckLoad;
				explicit Iterator(Package *head):
					pHead{head}, pCurrent(nullptr) {}

			public:
				SharedCuboid getFirstCuboid();
				SharedCuboid getNextCuboid();
		};

		TruckLoad() = default;
		TruckLoad(SharedCuboid pCuboid) {
			pHead = pTail =  new Package{pCuboid};
		}
		TruckLoad(const std::vector<SharedCuboid> &cuboids);
		TruckLoad(const TruckLoad &other);  // try to implement copy constructor

		// copy assignment operator
		TruckLoad& operator=(const TruckLoad& other);

		Iterator getIterator() const { return Iterator{pHead}; }
		void addCuboid(SharedCuboid aCuboid);
		bool removeCuboid(SharedCuboid aCuboid);
		// void listCuboid() const;

		// overloading subscript operator
		SharedCuboid& operator[](size_t index);
};

std::ostream& operator<<(std::ostream& out, const TruckLoad& load);

#endif
