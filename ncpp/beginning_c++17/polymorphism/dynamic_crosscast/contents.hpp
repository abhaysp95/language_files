#ifndef _CONTENTS_HPP
#define _CONTENTS_HPP

#include <iostream>

class Contents {
	private:
		std::string type{};

	public:
		Contents(std::string_view type)
			:type{type} {
				std::cout << "Contents constructor called" << std::endl;
			}

		inline void showType() const {
			std::cout << "just a test from Contents" << std::endl;
		}
};

#endif
