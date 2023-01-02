#include "customer.hpp"
#include <sstream>
#include <string>

Customer::Customer(std::string_view name,
		std::string_view surname,
		std::string_view street,
		int streetNumber,
		std::string_view city)
	: name{name}
	, surname{surname}
	, street{street}
	, streetNumber{streetNumber}
	, city{city} {}

std::string Customer::toString() const {
	std::stringstream result;
	result << name;
	result << ' ' << surname;
	result << ' ' << street;
	result << ' ' << std::to_string(streetNumber);
	result << ' ' << city;

	return result.str();
}
