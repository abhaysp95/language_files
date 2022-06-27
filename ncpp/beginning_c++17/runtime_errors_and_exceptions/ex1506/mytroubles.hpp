#ifndef _MYTROUBLES_HPP
#define _MYTROUBLES_HPP

#include <string>
#include <string_view>

class Trouble {
	private:
		std::string message;
	public:
		Trouble(std::string_view str = "There's a problem"): message{str} {}
		virtual ~Trouble() = default;

		virtual std::string_view what() const { return message; }
};

class MoreTrouble: public Trouble {
	public:
		MoreTrouble(std::string_view str = "There's more trouble...")
			:Trouble{str} {}
};

class BigTrouble: public MoreTrouble {
	public:
		BigTrouble(std::string_view str = "Really big trouble...")
			:MoreTrouble{str} {}
};

#endif
