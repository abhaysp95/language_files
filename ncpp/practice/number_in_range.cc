// print all the numbers in range provided by user

#include <iostream>

// recursive function to print numbers
int print_numbers(int fnum, int snum) {
	if (fnum == snum) {
		return 0;
	}
	std::cout << fnum << std::endl;
	print_numbers(fnum + 1, snum);
	return 0;
}

// main function
int main() {
	int first_num = 0, second_num = 0;
	std::cout << "Enter the numbers: " << std::endl;
	std::cin >> first_num >> second_num;
	std::cout << "Numbers in range " << first_num << " and " << second_num
		<< " are: " << std::endl;
	print_numbers(first_num, second_num);
	return 0;
}
