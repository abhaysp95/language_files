// main file

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	size_t weight{};
	cin >> weight;
	cout << (weight > 2 && weight % 2 == 0 ? "YES" : "NO") << endl;
	return 0;
}