// header file

#ifndef _GUARD_VECTOR_HPP_
#define _GUARD_VECTOR_HPP_

class Vector {
	private:
		int _sz;
		double* _elem;
	public:
		Vector(int s);
		double& operator[](int i);
		int size();
};

#endif