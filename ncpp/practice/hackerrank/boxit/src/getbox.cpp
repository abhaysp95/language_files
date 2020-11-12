#include "../inc/getbox.hpp"

namespace test {
	Box::Box() {
		this->l = 0;
		this->b = 0;
		this->h = 0;
	}
	Box::Box(int l, int b, int h) {
		this->l = l;
		this->b = b;
		this->h = h;
	}
	Box::Box(const Box& box) {
		this->l = box.l;
		this->b = box.b;
		this->h = box.h;
	}
	int Box::getLength() const { return this->l; }
	int Box::getWidth() const { return this->b; }
	int Box::getHeight() const { return this->h; }
	int Box::CalculateVolume() const {
		return l * b * h;
	}
	bool Box::operator<(Box& box) const {
		if (this->l < box.l
				|| ((this->b < box.b) && (this->l == box.l))
				|| ((this->h < box.h) && (this->l == box.l) && (this->b == box.b))) {
			return true;
		}
		return false;
	}
	std::ostream& operator<<(std::ostream& os, test::Box& box) {
		std::cout << "{ " << box.getLength() << ", " << box.getWidth() << ", " << box.getHeight() << " }" << std::endl;
		return os;
	}
};
