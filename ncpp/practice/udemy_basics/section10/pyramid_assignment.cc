// make the string pyramid

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string str_for_pyramid {};
	getline(cin, str_for_pyramid);

	size_t len_of_pyramid(str_for_pyramid.length());
	string space (len_of_pyramid, ' ');

	cout << space << str_for_pyramid << endl;

	size_t i {};
	while (i <= len_of_pyramid) {
		string left_triangle_chars(str_for_pyramid.substr(0, i));
		// cout << left_triangle_chars << endl;

		string right_triangle_chars {};
		size_t len_left_triangle{left_triangle_chars.length()};

		// size_t for j will not work
		for (int j{len_left_triangle - 2}; j >= 0; --j) {
			right_triangle_chars += left_triangle_chars.at(j);
		}
		cout << space << left_triangle_chars << right_triangle_chars << endl;
		space.erase(0, 1);
		i++;
	}

	// Another approach

	//string str_for_pyramid {};
	//getline(cin, str_for_pyramid);

	//size_t len_of_pyramid {str_for_pyramid.length()};

	//for (int i{}; i < len_of_pyramid; ++i) {
		//for (int space {}; space < (len_of_pyramid - 1) - i; ++space) {
			//cout << " ";
		//}
		//for (int j {}; j <= i; ++j) {
			//cout << str_for_pyramid.at(j);
		//}
		//for (int k {i - 1}; k >= 0; --k) {
			//cout << str_for_pyramid.at(k);
		//}
		//cout << endl;
	//}

	return 0;
}
