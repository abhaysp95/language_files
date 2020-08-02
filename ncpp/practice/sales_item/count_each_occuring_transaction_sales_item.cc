// reads several transactions and counts how many transactions occur for each
// ISBN

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item value1, value2;
	int count = 0;
	std::cin >> value1;
	count = 1;
	while (std::cin >> value2) {
		if (value1.isbn() == value2.isbn()) {
			++count;
		}
		else {
			std::cout << "\nTransaction for " << value1.isbn() << " occured "
				<< count << " times." << std::endl;
			value1 = value2;
			count = 1;  // cause value2 is already changed
		}
	}
	std::cout << "\nTransaction for " << value1.isbn() << " occured "
		<< count << " times." << std::endl;
	return 0;
}
