// header file

#ifndef _GUARD_VECTOR_HPP_
#define _GUARD_VECTOR_HPP_

#include <iostream>

class Vector {
	private:
		int _sz;
		double* _elem;
	public:
		Vector(std::initializer_list<double> lst);
		Vector(int s);
		~Vector();
		double& operator[](int i);
		int size();
};

#endif