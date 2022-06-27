#include "mytroubles.hpp"

#include <iostream>
#include <typeinfo>

int main(void) {
	Trouble trouble;
	MoreTrouble more_trouble;
	BigTrouble big_trouble;

	for (size_t i {}; i < 7; i++) {
		try {
			try {
				if (i == 3) {
					throw trouble;
				} else if (i == 5) {
					throw more_trouble;
				} else if (i == 6) {
					throw big_trouble;
				}
			} catch (const Trouble& t) {
				if (typeid(t) == typeid(Trouble)) {
					std::cout << "Trouble object caught in inner block: " << t.what() << std::endl;
				} else {
					throw;  // rethrow current exception
				}
			}
		/* } catch(const Trouble& t) {  // you can just as well divide this
			std::cout << typeid(t).name() << " object caught in outer block: " << t.what() << std::endl;
		} */

		} catch(const BigTrouble& t) {
			std::cout << typeid(t).name() << " object caught in outer block: " << t.what() << std::endl;
		} catch (const MoreTrouble& t) {
			std::cout << typeid(t).name() << " object caught in outer block: " << t.what() << std::endl;
		}

		std::cout << "End of for loop (after catch block) - i: " << i << std::endl;
	}

	return 0;
}
