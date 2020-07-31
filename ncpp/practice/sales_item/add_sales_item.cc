// add two Sales_item

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item item1, item2;
	// read a pair of transaction
	std::cin >> item1 >> item2;
	// print the sum
	std::cout << item1 + item2;
	return 0;
}
