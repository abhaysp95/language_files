// split the bills

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

// this function is just for demonstration purpose of cmath functions
int main() {
	double bill_total {102.85};
	size_t number_of_guests {5};

	double round_down_to_dollar {floor(bill_total)};
	double round_to_dollar {round(bill_total)};
	double round_up_to_cents {ceil(bill_total * 100) / 100};

	double individual_bill1 = round_down_to_dollar / number_of_guests;
	double individual_bill2 = round_to_dollar / number_of_guests;
	double individual_bill3 = round_up_to_cents / number_of_guests;

	cout << "ROUND_DOWN_TO_DOLLAR: " << round_down_to_dollar << endl;
	cout << "ROUND_TO_DOLLAR: " << round_to_dollar << endl;
	cout << "ROUND_UP_TO_CENTS: " << round_up_to_cents << endl;


	cout << "individual_bill1: " << individual_bill1 << endl;
	cout << "individual_bill2: " << individual_bill2 << endl;
	cout << "individual_bill3: " << individual_bill3 << endl;
	return 0;
}
