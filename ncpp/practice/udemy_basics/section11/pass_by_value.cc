// demonstrating pass by value feature of C++

#include <iostream>
#include <vector>
#include <string>

void update_name(std::vector<std::string> );
void print_name(std::vector<std::string> );

void update_name(std::vector<std::string> got_name) {
	std::vector<std::string> new_name{"CHANDLER", "BING"};
	for (std::string name: new_name) {
		got_name.push_back(name);
	}
	std::cout << "----------------------------" << std::endl;
	std::cout << "inside update_name function: " << std::endl;
	print_name(got_name);
	std::cout << "----------------------------" << std::endl;
}

void print_name(std::vector<std::string> got_name) {
	for (std::string name: got_name) {
		std::cout << name;
		if (name != got_name.at(got_name.size() - 1)) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	std::vector<std::string> name_is{"JOEY", "TRIBBIANI"};

	std::cout << "----------------------------" << std::endl;
	std::cout << "Before updating name_is: " << std::endl;
	print_name(name_is);
	std::cout << "----------------------------" << std::endl;

	name_is.push_back(", ");
	update_name(name_is);

	std::cout << "----------------------------" << std::endl;
	std::cout << "After updating: " << std::endl;
	name_is.pop_back();
	print_name(name_is);
	std::cout << "----------------------------" << std::endl;

	return 0;
}
