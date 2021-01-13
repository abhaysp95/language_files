// main file

#include <iostream>
#include <iomanip>
#include <ios>
#include <locale>

int main(int argc, char **argv) {
	std::cout.imbue(std::locale("en_US.utf8"));
	std::cout << "Left fill:\n" << std::left << std::setfill('*')
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << std::hex << std::showbase << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Another left fill:\n" << std::left << std::setfill('*')
		<< std::setw(12) << -1.23 << '\n'
		<< std::hex << std::showbase << 42 << '\n'
		<< std::put_money(123, true) << "\n\n";

	std::cout << "Internal fill:\n" << std::internal << std::setfill('*')
		<< std::setw(18) << -1.23 << '\n'
		<< std::setw(18) << std::hex << std::showbase << 42 << '\n'
		<< std::setw(18) << std::put_money(123, true) << "\n\n";

	std::cout << "Internal fill:\n" << std::right << std::setfill('*')
		<< std::setw(15) << -1.23 << '\n'
		<< std::setw(15) << std::hex << std::showbase << 42 << '\n'
		<< std::setw(15) << std::put_money(123, true) << "\n\n";
	return 0;
}