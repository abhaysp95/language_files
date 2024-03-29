#ifndef _CARTON_HPP
#define _CARTON_HPP

#include "box.hpp"

class Carton: public Box {
	private:
		std::string material;

	public:
		Carton(double l, double b, double h, std::string_view str)
			: Box{l, b, h} {
				material = str;
			}

		~Carton() {
			std::cout << "Box destructor called" << std::endl;
		}

		inline double volume() const override {
			const double vol {(length - 0.5) * (width - 0.5) * (height - 0.5)};
			return vol > 0.0 ? vol : 0.0;
		}

		inline double surface() const {
			return (length * width
					+ width * height
					+ height * length);
		}
};

#endif
