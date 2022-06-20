#ifndef _TRUCKLOADV2_HPP
#define _TRUCKLOADV2_HPP

#include "cuboid.hpp"

#include <memory>
#include <vector>

using SharedCuboid = std::shared_ptr<Cuboid>;

class TruckLoadv2 {
	private:
		class Package {
			SharedCuboid pCuboid;
			Package *pNext;

			Package(SharedCuboid aCuboid):
				pCuboid{aCuboid}, pNext{nullptr} {}
			~Package() { delete pNext; }  // delete with nullptr does nothing
		};

		Package *pHead {};
		Package *pTail {};

	public:
		class Iterator {
			private:
				Package *pHead {};
				Package *pCurrent {};

				friend class TruckLoadv2;
				explicit Iterator(Package *head):
					pHead{head}, pCurrent(nullptr) {}

			public:
				SharedCuboid getFirstCuboid();
				SharedCuboid getNextCuboid();
		};

		TruckLoadv2() = default;
		TruckLoadv2(SharedCuboid pCuboid);
		TruckLoadv2(const std::vector<SharedCuboid> &cuboids);
		TruckLoadv2(const TruckLoadv2 &src);

		Iterator getIterator() const { return Iterator{pHead}; }
		void addCuboid(SharedCuboid aCuboid);
		bool removeCuboid(SharedCuboid aCuboid);
		void listCuboid() const;
};

#endif
