#ifndef _CARTOON_HPP
#define _CARTOON_HPP

#include "box.hpp"

#include <iostream>

class Carton: private Box {
	private:
		std::string material;
	public:
		using Box::volume;   // changing the access specification of inherited member
		Carton() {
			std::cout << "Carton()\n";
		}
		explicit Carton(std::string_view mat):
			material{mat} {
				std::cout << "Carton(string)\n";
		}
		explicit Carton(double s, std::string_view mat):
			Box{s}, material {mat} {
				std::cout << "Carton(double, string)\n";
		}
		explicit Carton(double l, double w, double h, std::string_view mat):
			Box{l, w, h}, material{mat} {
				std::cout << "Carton(double, double, double, string)\n";
		}
};

#endif

/**
  * NOTE:
  * Although inherited member variables that are not private to the base class
  * can be accessed from a derived class, they can’t be initialized in the
  * initialization list for a derived class constructor. If you want to
  * initialize the inherited member variables explicitly, you could do it in
  * the body of the derived class constructor
  */
