#ifndef GETBOX_HPP
#define GETBOX_HPP

#include <iostream>

namespace test {
	class Box {
		private:
			int l, b, h;
		public:
			Box();
			Box(int l, int b, int h);
			Box(const Box& box);
			int getLength() const;
			int getWidth() const;
			int getHeight() const;
			int CalculateVolume() const;
			bool operator<(Box& b) const;
			friend std::ostream& operator<<(std::ostream& os, test::Box& box);
	};
};

#endif

// https://stackoverflow.com/questions/23335209/error-overloaded-operator-must-be-a-binary-operator-has-3-parameters
