// main file

#include <iostream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

void case_substr(string in, string& out) {
	if (in.empty()) {
		cout << out << '\n';
		return;
	}
	string out1{out}, out2{out};
	char c = in.at(0);
	out1 += c;
	out2 += toupper(c);
	in.erase(0, 1);
	case_substr(in, out1);
	case_substr(in, out2);
}

int main(int argc, char **argv) {
	string in{}, out{};
	cin >> in;
	case_substr(in, out);
	return 0;
}