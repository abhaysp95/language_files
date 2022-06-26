#ifndef _CEREALPACK_HPP
#define _CEREALPACK_HPP

#include "carton.hpp"

class CerealPack: public Carton {
	private:
		std::string msg{};

	public:
		CerealPack();
		CerealPack(double l, double b, double h, std::string_view mat, std::string_view msg):
			Carton(l, b, h, mat) {
				std::cout << "CerealPack constructor" << std::endl;
				this->msg = msg;
			}
		virtual ~CerealPack() {
			std::cout << "CerealPack destructor called" << std::endl;
		}

		inline double volume() const override {
			return Carton::volume() * 0.50;  // just temp
		}
};

#endif
