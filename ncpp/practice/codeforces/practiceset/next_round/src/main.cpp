// main file

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	size_t count{}, pos{}, passed{};
	cin >> count >> pos;
	int scores[count];
	for (size_t i = 0; i < count; ++i) {
		cin >> *(scores + i);
	}

	for (size_t i = 0; i < count; ++i) {
		(*(scores + i) > 0) && (*(scores + i) >= *(scores + pos - 1)) ? passed++ : 0;
	}

	cout << passed << endl;
	return 0;
}