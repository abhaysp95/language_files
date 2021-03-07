// header file

#ifndef _GUARD_CONTAINER_HPP_
#define _GUARD_CONTAINER_HPP_

class Container {
	public:
		virtual double operator[](int i) const = 0;  // pure virtual function(=0)
		virtual int size() const = 0;
		virtual ~Container();
};

#endif
