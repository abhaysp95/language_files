#pragma once

namespace uiuc {
	class Cube {
		private:
			double length_;
		public:
			Cube();
			Cube(double length);
			Cube(const Cube& obj);
			Cube& operator=(const Cube& obj);
			double getVolume();
			double getSurfaceArea();
			void setLength(double length);
	};
};
