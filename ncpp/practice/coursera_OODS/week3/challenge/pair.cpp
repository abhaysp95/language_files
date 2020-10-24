#include <iostream>
#include "pair.hpp"

namespace chlng{
	Pair::Pair(int a, int b) {
		pa = new int(a);
		pb = new int(b);
		std::cout << "constructor with two args" << std::endl;
	}

	Pair::Pair(const Pair& obj) {
		this->pa = new int(*(obj.pa));
		this->pb = new int(*(obj.pb));
		std::cout << "copy constructor" << std::endl;
	}

	Pair::~Pair() {
		std::cout << "deleting current object" << std::endl;
		//delete this;
	}
	void Pair::print() {
		std::cout << "pa -> " << *pa << std::endl;
		std::cout << "pb -> " << *pb << std::endl;
	}
	bool Pair::compare(const Pair& obj) {
		return ((*pa == *(obj.pa)) && (*pb == *(obj.pb)));
	}
	bool Pair::compare(const Pair* obj) {
		return (*pa == *(obj->pa) && (*pb == *(obj->pb)));
	}
};
