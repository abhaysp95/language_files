// cpp file for "list_container.hpp"

#include "../inc/list_container.hpp"
#include <stdexcept>

List_Container::List_Container() {}
List_Container::List_Container(std::initializer_list<double> il): _ld(il) {}
List_Container::~List_Container() {}

double List_Container::operator[](int i) const {
	for (const double& x: this->_ld) {
		if (i-- == 0) {
			return x;
		}
	}
	throw std::out_of_range("");
}

int List_Container::size() const { return this->_ld.size(); }
