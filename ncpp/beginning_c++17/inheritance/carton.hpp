#ifndef _CARTOON_HPP
#define _CARTOON_HPP

#include "box.hpp"

#include <iostream>

class Carton: private Box {
	private:
		std::string material;
	public:
		using Box::volume;   // changing the access specification of inherited member
		explicit Carton(std::string_view mat = "Cardboard"):
			material{mat} {}
};

#endif
