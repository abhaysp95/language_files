#ifndef _TOOMANYEXCEPTIONS_HPP
#define _TOOMANYEXCEPTIONS_HPP

#include <stdexcept>

class TooManyExceptions: public std::exception {
	const char* what() const noexcept override {
		return "too many exception";
	}
};

#endif
