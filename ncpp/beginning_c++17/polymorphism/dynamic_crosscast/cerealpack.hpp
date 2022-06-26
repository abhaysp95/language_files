#ifndef _CEREALPACK_HPP
#define _CEREALPACK_HPP

#include "carton.hpp"
#include "contents.hpp"

class CerealPack: public Carton, public Contents {
	private:
		std::string msg{};

	public:
		CerealPack();
		CerealPack(double l, double b, double h, std::string_view mat, std::string_view msg):
			Carton(l, b, h, mat), Contents("cereal") {
				std::cout << "CerealPack constructor" << std::endl;
				this->msg = msg;
			}
		CerealPack(double l, double b, double h, std::string_view mat, std::string_view msg, std::string type):
			Carton(l, b, h, mat), Contents(type) {
				std::cout << "CerealPack constructor" << std::endl;
				this->msg = msg;
			}
		virtual ~CerealPack() {
			std::cout << "CerealPack destructor called" << std::endl;
		}

		inline double volume() const override {
			std::cout << "CerealPack volume" << std::endl;
			return Carton::volume() * 0.50;  // just temp
		}
};

#endif
