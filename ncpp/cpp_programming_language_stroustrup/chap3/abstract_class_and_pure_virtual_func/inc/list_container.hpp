// header file

#ifndef _GUARD_LIST_CONTAINER_HPP_
#define _GUARD_LIST_CONTAINER_HPP_

#include "../inc/container.hpp"
#include <iostream>
#include <list>

class List_Container: public Container {
	private:
		std::list<double> _ld;
	public:
		List_Container();
		List_Container(std::initializer_list<double> il);
		~List_Container();

		double operator[](int i) const override;
		int size() const override;
};

#endif
