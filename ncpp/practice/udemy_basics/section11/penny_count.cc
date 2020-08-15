// recursive example of doubling penny for n days


#include <iostream>

double penny_count(int days, double amount = 0.01);

double penny_count(int days, double amount) {
	if (days <= 1) {
		return amount;
	}
	return penny_count(--days, amount + amount);
}

int main() {
	int days {};
	double starting_amount {};
	std::cout << "Enter the days and starting_amount: " << std::endl;
	std::cin >> days >> starting_amount;
	double total_amount {};
	if (starting_amount == 0) {
		total_amount = penny_count(days);
	}
	else {
		total_amount = penny_count(days, starting_amount);
	}
	std::cout << total_amount << std::endl;
	return 0;
}
