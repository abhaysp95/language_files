// program that reads several transactions for the same ISBN and writes sum
// of all the transactions read

// What I'll do is print sum of the ISBN's that are same

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item item1, item2, item3;
	std::cout << "Enter the set of books for Sales_item: " << std::endl;
	std::cin >> item1;
	item3 = item1;
	while(std::cin >> item2) {
		if(item1.isbn() == item2.isbn()) {
			item3 += item2;
			std::cout << item3 << std::endl;  // indicate success
		}
		else {
			std::cerr << "The ISBN is not same with the first set\n"
				<< std::endl;
			return -1;  // indicate failure
		}
	}
	std::cout << "Exiting Now!" << std::endl;
	return 0;
}
