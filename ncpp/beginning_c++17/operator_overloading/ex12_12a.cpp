#include "message.hpp"

#include <iostream>

void why_not_default_assignment_operator() {
	Message message;
	{
		Message beware{"careful"};
		std::cout << "beware: " << beware.getText() << std::endl;
		message = beware;
		std::cout << "message: " << message.getText() << std::endl;
	}
	std::cout << "message: " << message.getText() << std::endl;

	Message beware {"Careful"};
	Message warning;
	warning = beware;                       // Call assignment operator
	Message otherWarning{warning};   // call copy constructor
}

int main(void) {
	why_not_default_assignment_operator();
	return 0;
}
