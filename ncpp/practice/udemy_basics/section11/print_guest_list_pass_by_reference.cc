// print and update the guest list, example for pass by reference to function

#include <iostream>
#include <string>
#include <vector>

void print_guest_list(const std::vector<std::string> stooges);
void update_guest_list(std::vector<std::string> &stooges);

void print_guest_list(const std::vector<std::string> stooges) {
	size_t count {};
	size_t stooge_size = stooges.size();
	for (std::string stoog: stooges) {
		std::cout << stoog;
		count++;
		if (count < stooge_size) {
			std::cout << ' ';
		}
	}
	std::cout << "\n" << std::endl;
}

void update_guest_list(std::vector<std::string> &stooges) {
	for (std::string &stoog: stooges) {  // search more about range declaretion
		stoog = ' ';
	}
}

int main() {
	std::vector<std::string> three_stooges{"Larry", "Moo", "Curly"};

	std::cout << "\nBefore updating list: " << std::endl;
	print_guest_list(three_stooges);
	update_guest_list(three_stooges);
	std::cout << "After updating list: " << std::endl;
	print_guest_list(three_stooges);

	return 0;
}
