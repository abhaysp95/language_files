// a simple C++ exception type

#ifndef _DBEXCEPTION_HPP
#define _DBEXCEPTION_HPP

#include <stdexcept>

class DatabaseException: public std::runtime_error {
	public:
		using std::runtime_error::runtime_error;  // Inherit constructor
};

#endif
