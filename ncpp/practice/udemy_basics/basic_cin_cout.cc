// showing basic cin and cout

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int num;
	double dec_num;
	cout << "Enter the integer: " << endl;
	cin >> num;
	cout << "Enter the decimal number: " << endl;
	cin >> dec_num;
	cout << "You entered " << num << " and " << dec_num << endl;
	return 0;
}
