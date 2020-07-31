// reads a set of book sales transactions, writing each transaction to stdout

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item book;
	while (std::cin >> book) {
		std::cout << book << std::endl;
	}
	return 0;
}
