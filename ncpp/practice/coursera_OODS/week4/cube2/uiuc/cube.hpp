#pragma once

#include "HSLAPixel.hpp"

namespace uiuc {
	class Cube {
		public:
			Cube(double length, HSLAPixel color);
			double getVolume() const;
			double getSurfaceArea() const;
			void setLength(double length);
			double getLength() const;
		private:
			double length_;
			HSLAPixel color_;
	};
};
