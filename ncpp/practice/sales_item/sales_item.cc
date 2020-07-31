// reading and writing Sales_item

#include <iostream>
#include "Sales_item.h"

int main() {
	// creating a Sales_item object named book
	Sales_item book;
	// read ISBN, number of copies sold, and sales price
	std::cin >> book;
	// write ISBN, number of copies sold, total revenue and average price
	std::cout << book << std::endl;
}

/*
 *ISBN stands for => International Standard Book Number
*/
