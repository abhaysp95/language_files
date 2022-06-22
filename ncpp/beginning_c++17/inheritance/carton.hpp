#ifndef _CARTOON_HPP
#define _CARTOON_HPP

#include "box.hpp"

#include <iostream>

class Carton: private Box {
	private:
		std::string material;
		double thickness{0.125};  // thickness in inches
		double density{0.2};  // density in pound/cubic inch

	public:
		using Box::Box;  // inherit Base-class constructor (default constructors are never inherited)
		using Box::volume;   // changing the access specification of inherited member
		Carton() {
			std::cout << "Carton()\n";
		}
		explicit Carton(std::string_view mat)
			:material{mat} {
				std::cout << "Carton(string_view)\n";
		}
		explicit Carton(double s, std::string_view mat)
			:Carton{s, s, s, mat} {
				std::cout << "Carton(double, string_view)\n";
		}
		explicit Carton(double l, double w, double h, std::string_view mat)
			:Box{l, w, h}, material{mat} {
				std::cout << "Carton(double, double, double, string_view)\n";
		}
		explicit Carton(double l, double w, double h, std::string_view mat, double dense, double thick)
			:Carton{l, w, h, mat} {
				density = dense;
				thickness = thick;
				std::cout << "Carton(double, double, double, string_view, double, double\n)";
		}

		Carton(const Carton& other): Box{other}, material{other.material} {
			std::cout << "Carton copy constructor called\n";
		}

		~Carton() {
			std::cout << "Carton destructor called\n";
		}

		inline double getWeight() const {
			return 2.0 * (getLength() * getWidth()
					+ getWidth() * getHeight()
					+ getHeight() * getLength()) * density * thickness;
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
