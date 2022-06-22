#ifndef _CEREAlPACK_HPP
#define _CEREAlPACK_HPP

#include "carton.hpp"
#include "contents.hpp"

#include <iostream>

class CerealPack: public Carton, public Contents {
	public:
		using Carton::volume;  // written to make ex13_06b work
		using Contents::getWeight;  // written to make ex13_06b work

		explicit CerealPack(double l, double b, double h, std::string_view cerealType)
			:Carton{l, b, h}, Contents{cerealType} {
				std::cout << "CerealPack(double, double, double, string_view)\n";
				// setVolume(0.9 * Carton::volume());  // works too
				Contents::setVolume(0.9 * Carton::volume());  // more clear
		}

		~CerealPack() {
			std::cout << "CerealPack destructor called\n";
		}
};

#endif
