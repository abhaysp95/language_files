#include "util.hpp"

namespace statclass {
	void A::setObnum() {
		count_++;
		obnum_ = count_;
	}
	int A::getObnum() {
		return obnum_;
	}
	int A::getCount() {
		return count_;
	}
	void C::setA(int a) {
		this -> a = a;
	}
	void C::addA(C a, C b) {
		this -> a = a.a + b.a;
	}
};
