#ifndef _TRUCKLOAD_H_
#define _TRUCKLOAD_H_

#include "package.hpp"
#include <vector>

class TruckLoad {
	private:
		Package *pHead {};
		Package *pCurrent {};
		Package *pTail {};

	public:
		TruckLoad() = default;
		TruckLoad(SharedCuboid pCuboid) {
			pHead = pCurrent = pTail = new Package {pCuboid};
		}
		TruckLoad(const std::vector<SharedCuboid> &cuboids);
		TruckLoad(const TruckLoad &src);

		~TruckLoad();

		SharedCuboid getFirstCuboid();
		SharedCuboid getNextCuboid();
		void addCuboid(SharedCuboid cuboid);
		bool removeCuboid(SharedCuboid cuboid);
		void listCuboid() const;
};

#endif
