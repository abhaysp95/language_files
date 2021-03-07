// header file

#ifndef _GUARD_VECTOR_HPP_
#define _GUARD_VECTOR_HPP_

#include <iostream>

class Vector {
	private:
		double* _elem;
		int _sz;
	public:
		Vector(std::initializer_list<double> lst);
		Vector(int s);
		~Vector();
		double& operator[](int i) const;
		int size() const;
};

#endif