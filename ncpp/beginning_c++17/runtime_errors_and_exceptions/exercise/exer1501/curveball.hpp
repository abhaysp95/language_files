#ifndef _CURVEBALL_HPP
#define _CURVEBALL_HPP

#include <iostream>
#include <exception>

class CurveBall: public std::exception {
	private:
		std::string msg;
	public:
		CurveBall(std::string_view str = "CurveBall Exception happened")
			: msg{str} {}
		virtual const char * what() const noexcept override {
			return this->msg.c_str();
		}
};

#endif
