#pragma once

namespace uiuc {
	class Cube {
		public:
			double getVolume();
			double getSurfaceArea();
			void setLength(double length);
		private:
			double length_;
	};
};
