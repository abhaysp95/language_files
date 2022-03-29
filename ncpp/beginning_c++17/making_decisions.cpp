#include <array>
#include <cctype>
#include <iostream>

void fallthrough() {
	std::cout << "---------------" <<
		__PRETTY_FUNCTION__ << "---------------" << '\n';
	int ticket_number {10};
	switch (ticket_number) {
		case 929:
			std::cout << "Won Bonus!!!" << '\n';
			break;
		[[fallthrough]];  // not mendatory, shows that fallthrough is intentional (C++17)
		case 29:
		case 78:
			std::cout << "Won third prize!!!" << '\n';
			break;
		default:
			std::cout << "BLANK!!!" << '\n';
	}
	std::cout << "------------------------------------------------" << std::endl;
}

void initialization_statements() {
	std::cout << "---------------" <<
		__PRETTY_FUNCTION__ << "---------------" << '\n';
	int input{102};
	{  // since lower is only used by the if statement creating scope is good idea
		auto lower{static_cast<char>(std::tolower(input))};
		if (std::isalpha(lower)) {
			std::cout << "Entered lower letter '" << lower << "'\n";
		}
	}  // C++17 introduced new way to do this
	if (auto lower{static_cast<char>(std::tolower(input))}; std::isalpha(lower)) {
		std::cout << "Entered lower letter '" << lower << "'\n";
	}
	std::cout << "------------------------------------------------" << std::endl;
}

void array_braced_initializers_determine_size() {
	std::cout << "---------------" <<
		__PRETTY_FUNCTION__ << "---------------" << '\n';
	unsigned int arr[] {1, 2, 3, 4, 5};  // you don't need to tell size, unlike int arr[2] = {1, 2};
	// getting size
	std::cout << "Array size (sizeof method): " << sizeof(arr)/sizeof(arr[0]) << '\n';
	std::cout << "Array size (std::sizE): " << std::size(arr) << '\n';
	std::cout << "------------------------------------------------" << std::endl;
}

int main(int argc, char **argv) {
	fallthrough();
	initialization_statements();
	array_braced_initializers_determine_size();
}
