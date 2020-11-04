#ifndef CUBE_H
#define CUBE_H

#include "../shapes.hpp"
#include "HSLAPixel.hpp"

namespace uiuc {
	class Cube : public Shape {
		private:
			uiuc::HSLAPixel color_;
		public:
			Cube(double width, uiuc::HSLAPixel& color);
			double getVolume() const;
	};
};

#endif
