// the final bookstore program

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item total;
	// read the first transaction
	if (std::cin >> total) {
		Sales_item trans;
		// read and process remaining transaction
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;  // update the running total
			}
			else {
				std::cout << total << std::endl;  // print the grouped total
				total = trans;
			}
		}
		std::cout << total << std::endl;  // print the last transaction
	}
	else {
		// no input! warn the user
		std::cerr << "No data ?" << std::endl;
		return -1;  // indicate failure
	}
	return 0;
}
