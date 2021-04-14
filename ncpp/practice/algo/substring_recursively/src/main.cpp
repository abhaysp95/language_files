// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void get_substrings(string in, string& out) {
	// NOTE:  in(input string) should not be passed as reference
	if (in.empty()) {
		if (!out.empty())
			cout << out << '\n';
		return;
	}
	string out1 = out, out2 = out;
	char c = in.at(0);
	in.erase(0, 1);
	out2 += string{c};
	get_substrings(in, out1);
	get_substrings(in, out2);
}

int main(int argc, char **argv) {
	string in{}, out{};
	cin >> in;
	cout << "Input: " << in << '\n';
	get_substrings(in, out);
	cout << endl;
	return 0;
}