// header file

#ifndef _GUARD_VECTOR_CONTAINER_HPP_
#define _GUARD_VECTOR_CONTAINER_HPP_

#include "../inc/container.hpp"
#include "../inc/vector.hpp"

class Vector_Container: public Container {
	private:
		Vector _v;
	public:
		Vector_Container(int s);
		~Vector_Container();
		double operator[](int i) const override;
		int size() const override;
};

#endif
