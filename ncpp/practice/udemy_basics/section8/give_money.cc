// user enters cents and we give then money back appropraiely

#include <iostream>

using namespace std;

int main() {
	// each values are w.r.t cents
	const unsigned short dollar_value {100};
	const unsigned short quarter_value {25};
	const unsigned short dime_value {10};
	const unsigned short nickel_value {5};
	const unsigned short penny_value {1};
	unsigned int cents {};

	cout << "Enter the money in cents: ";
	cin >> cents;

	unsigned int dollars{}, quarters{}, dime{}, nickel{}, penny{}, balance{};

	dollars = cents / dollar_value;
	balance = cents % dollar_value;

	quarters = balance / quarter_value;
	balance %= quarter_value;

	dime = balance / dime_value;
	balance %= dime_value;

	nickel = balance / nickel_value;
	balance %= nickel_value;

	penny = balance / penny_value;
	balance %= penny_value;

	cout << "You have: " << endl;
	cout << "\tdollars: " << dollars << endl;
	cout << "\tquarters: " << quarters << endl;
	cout << "\tdimes: " << dime << endl;
	cout << "\tnickels: " << nickel << endl;
	cout << "\tpennies: " << penny << endl;

	return 0;
}
