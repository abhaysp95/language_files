// main file

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void substrs(string openbr, string closebr, string& out) {
	if (openbr.empty() && closebr.empty()) {
		cout << out << '\n';
		return;
	}
	if (openbr.size() <= closebr.size()) {
		if (openbr.empty()) {
			out += closebr.at(0);
			closebr.erase(0, 1);
			substrs(openbr, closebr, out);
		}
		else {
			if (openbr.size() == closebr.size()) {
				out += openbr.at(0);
				openbr.erase(0, 1);
				substrs(openbr, closebr, out);
			}
			else {
				string out1{out}, out2{out};
				char c = openbr.at(0);
				out1 += c;
				substrs(openbr.erase(0, 1), closebr, out1);
				openbr = openbr + c;
				c = closebr.at(0);
				out2 += c;
				substrs(openbr, closebr.erase(0, 1), out2);
			}
		}
	}
}

int main(int argc, char **argv) {
	size_t count{};
	cin >> count;
	string openbr{}, closebr{}, out{};
	while (count > 0) {
		openbr += '(';
		closebr += ')';
		count--;
	}
	substrs(openbr, closebr, out);
	return 0;
}