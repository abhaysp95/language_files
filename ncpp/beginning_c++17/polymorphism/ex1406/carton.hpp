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

		inline double volume(int i = 50) const override {
			std::cout << "Carton parameter = " << i << std::endl;
			const double vol {(length - 0.5) * (width - 0.5) * (height - 0.5)};
			return vol > 0.0 ? vol : 0.0;
		}
};

#endif
