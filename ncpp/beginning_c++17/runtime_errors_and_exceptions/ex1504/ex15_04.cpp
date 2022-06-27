#include "mytroubles.hpp"
#include <iostream>

int main(void) {
	Trouble trouble;
	MoreTrouble more_trouble;
	BigTrouble big_trouble;

	for (size_t i {}; i < 7; i++) {
		try {
			if (i == 3) {
				throw trouble;
			} else if (i == 5) {
				throw more_trouble;
			} else if (i == 6) {
				throw big_trouble;
			}
		} catch (const BigTrouble& t) {
			std::cout << "BigTrouble object caught: " << t.what() << std::endl;
		} catch (const MoreTrouble& t) {
			std::cout << "MoreTrouble object caught: " << t.what() << std::endl;
		} catch (const Trouble& t) {
			std::cout << "Trouble object caught: " << t.what() << std::endl;
		}
		std::cout << "End of for loop (after the catch blocks) - i is " << i << std::endl;
	}

	return 0;
}
