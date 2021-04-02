// main file

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	size_t count{};
	cin >> count;
	int x{};
	string operation{};
	for (size_t i = 0; i < count; ++i) {
		cin >> operation;
		if (operation[0] == '+' || operation[1] == '+') {
			x++;
		}
		else if (operation[0] == '-' || operation[1] == '-') {
			x--;
		}
	}
	cout << x << endl;
	return 0;
}