#ifndef _CONTENTS_HPP
#define _CONTENTS_HPP

#include <iostream>

class Contents {
	private:
		std::string name;
		double volume{};  // in inches
		double density{0.03};  // in pound/cubic inch

	public:
		Contents(std::string_view name)
			:name{name} {
				std::cout << "Contents(string_view)\n";
		}
		explicit Contents(std::string_view name, double vol, double dense)
			:name{name}, volume{vol}, density{dense} {
				std::cout << "Contents(string_view, double, double)\n";
		}
		Contents() {
			std::cout << "Contents()\n";
		}

		~Contents() {
			std::cout << "Contents destructor called\n";
		}

		void setVolume(double vol) {
			volume = vol;
		}

		inline double getWeight() const {
			return volume * density;
		}
};

#endif
