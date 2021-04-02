// main file

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	size_t num_test{};
	cin >> num_test;
	vector<string> abbr_str{};
	string input_str{};
	while (cin >> input_str) {
		size_t str_size = input_str.size();
		if (str_size > 10) {
			// itoa is a function used to convert integer to string: itoa(int value, char* str, int base);
			// you may use itoa with C, for C++ string, use to_string() function
			string abbr = input_str.at(0) + to_string(str_size - 2) + input_str.at(str_size - 1);
			abbr_str.push_back(abbr);
		}
		else {
			abbr_str.push_back(input_str);
		}
	}
	for (string& abbr: abbr_str) {
		cout << abbr << '\n';
	}
	return 0;
}