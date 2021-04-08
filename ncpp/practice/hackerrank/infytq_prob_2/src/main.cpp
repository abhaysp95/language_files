// main file

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool is_beautiful_string(const string& str) {
	size_t ca{}, cb{}, cc{};
	for (const char& c: str) {
		if (c == 'a')
			ca++;
		else if (c == 'b')
			cb++;
		else if (c == 'c')
			cc++;
	}
	if ((ca == cb) && (cb == cc)) {
		return true;
	}
	return false;
}

int main(int argc, char **argv) {
	string str{};
	size_t bs_count{};
	cin >> str;
	cout << str << '\n' << "------------------\n";
	assert((str.size() >= 1) && (str.size() <= 1e5));
	// cout << string(str.begin(), str.begin() + 3);
	for (string::const_iterator citer = str.cbegin(); citer != str.cend() - 1; ++citer) {
		for (string::const_iterator sciter = citer + 1; sciter <= str.cend(); sciter++) {
			string substr = string{citer, sciter};
			if (is_beautiful_string(substr)) {  // string{citer, sciter} is explicit from left and implicit from right
				cout << substr << '\n';
				bs_count++;
			}
		}
	}
	cout << bs_count << endl;
	return 0;
}