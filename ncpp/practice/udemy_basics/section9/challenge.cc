// complete the challenge

#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fixed;
using std::setprecision;

int main() {
	char choice {};
	vector<short> list {};
	do {
		cout << "\nP - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the number" << endl;
		cout << "F - Find the element in the list" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "C - Clear the list" << endl;
		cout << "Q - Quit\n" << endl;
		cout << "Your choice: ";

		cin >> choice;
		cout << "\n" << endl;
		switch (choice) {
			case 'P':
			case 'p':
				cout << "[";
				for (short number: list) {
					cout << " " << number << " ";
				}
				cout << "]" << endl;
				break;
			case 'A':
			case 'a':
				{
					short add_num {};
					unsigned short count {};
					cout << "Enter the number? ";
					cin >> add_num;
					if (list.size() != 0) {
						for (short num: list) {
							if (add_num == num) {
								cout << "Sorry!, Duplicates not allowed\n" << endl;
								count++;
								break;
							}
						}
					}
					if (!count) {
						list.push_back(add_num);
						cout << "\n" << endl;
					}
				}
				break;
			case 'F':
			case 'f':
				{
					short find_num {};
					unsigned short count {};
					cout << "Enter the number to find: ";
					cin >> find_num;
					cout << "\n" << endl;
					for (short num: list) {
						if (num == find_num) {
							count++;
						}
					}
					if (count != 0) {
						cout << find_num << " occured " << count << " times in the list" << endl;
					}
					else {
						cout << "Can't find " << find_num << " in the list" << endl;
					}
				}
				break;
			case 'M':
			case 'm':
				{
					float mean {};
					short sum {};
					for (short num: list) {
						sum += num;
					}
					mean = static_cast<float>(sum) / list.size();
					cout << fixed << setprecision(2) << endl;
					cout << "Mean is: " << mean << "\n" << endl;
				}
				break;
			case 'S':
			case 's':
				{
					short min {list.at(0)};
					for (short num: list) {
						if (min > num) {
							min = num;
						}
					}
					cout << "Min is: " << min << "\n" << endl;
				}
				break;
			case 'L':
			case 'l':
				{
					short max {list.at(0)};
					for (short num: list) {
						if (max < num) {
							max = num;
						}
					}
					cout << "max is: " << max << "\n" << endl;
				}
				break;
			case 'C':
			case 'c':
				{
					cout << "Are you sure [Yy/Nn]? ";
					char del_choice {};
					cin >> del_choice;
					cout << endl;
					if (del_choice == 'y' || del_choice == 'Y') {
						cout << "OK, clearing the list...\n" << endl;
						list.clear();
					}
					else {
						cout << "List not cleared\n" << endl;
					}
				}
				break;
			case 'Q':
			case 'q':
				cout << "\n Exiting \n\n Goodbye! \n" << endl;
				break;
			default:
				cout << "Unknown Selection, Please try again!\n" << endl;
				break;
		}
	} while (choice != 'q' && choice != 'Q');
	return 0;
}

/* use ternary without the else part


   while, declaring a variable in switch-case it is important to provide it scope, or else you may error like

   crosses initialization of <datatype>
   jump to case label

   etc.
 */
