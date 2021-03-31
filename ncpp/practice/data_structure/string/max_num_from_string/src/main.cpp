// main file

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	string input{};
	cin >> input;
	cout << "Input string: " << input << "\n";

	// sort in decreasing order

	// std::greater<>() returns True, if a > b else False
	sort(input.begin(), input.end(), greater<int>());  // sorting in decreasing order

	cout << "Biggest number: " << input << "\n";

	return 0;
}