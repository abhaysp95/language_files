#ifndef _NUMBEREXCEPTIONS_HPP
#define _NUMBEREXCEPTIONS_HPP

#include <stdexcept>

class NotANumber: public std::domain_error {
	public:
		explicit NotANumber(const std::string& msg = "value is not a number")
			: std::domain_error {msg} {}
		// virtual const char* what() const noexcept;
};

class NegativeNumber: public std::domain_error {
	public:
		explicit NegativeNumber(const std::string& msg = "value is negative number")
			: std::domain_error {msg} {}
		// virtual const char* what() const noexcept;
};

class OddNumber: public std::domain_error {
	public:
		explicit OddNumber(const std::string& msg = "value is odd number")
			: std::domain_error {msg} {}
		// virtual const char* what() const noexcept;
};

#endif
