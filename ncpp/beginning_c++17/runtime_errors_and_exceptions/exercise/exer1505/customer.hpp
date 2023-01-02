// a simple C++ customer class

#ifndef _CUSTOMER_HPP
#define _CUSTOMER_HPP

#include <string>

class Customer {
	private:
		std::string name;
		std::string surname;
		std::string street;
		int streetNumber;
		std::string city;

	public:
		Customer(std::string_view name,
				std::string_view surname,
				std::string_view street,
				int streetNumber,
				std::string_view city);

		std::string toString() const;
};

#endif
