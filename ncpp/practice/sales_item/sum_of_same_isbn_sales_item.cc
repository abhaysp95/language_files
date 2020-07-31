// produce sum of Sales item object having same ISBN

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item item1, item2;
	while (std::cin >> item1 >> item2) {
		std::cout << "First item entered " << item1 << std::endl;
		std::cout << "Second item entered " << item2 << std::endl;
		if (item1.isbn() == item2.isbn()) {
			std::cout << "Sum is " << item1 + item2 << std::endl;
		}
		else {
			std::cerr << "ISBN is not same for the entered set of books"
				<< std::endl;
			return -1;
		}
	}
	std::cout << "Exiting Now!" << std::endl;
	return 0;
}
