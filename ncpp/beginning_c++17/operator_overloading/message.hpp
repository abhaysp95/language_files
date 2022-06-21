#ifndef _MESSAGE_HPP
#define _MESSAGE_HPP

#include <iostream>
#include <string_view>

class Message {
	private:
		std::string* pText {nullptr};
	public:
		Message() = default;  // if not default initializing a raw pointer
							  // member, do it here then
		explicit Message(std::string_view msg):
			pText{new std::string(msg)} {}
		~Message() { delete pText; }

		// copy assignment operator
		Message& operator=(const Message& msg) {  // assignment operators can
												  // be overloaded for
												  // different types too
			if (this != &msg) {  // to prevent problems from self assignment
				delete pText;  // delete the previous stored message
				pText = new std::string(msg.getText());
			}
			return *this;
		}

		std::string_view getText() const { return *pText; }
};

#endif
