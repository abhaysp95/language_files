#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void get_substring(string in, string& out, vector<string>& substrs) {
	if (in.empty()) {
		if (!out.empty())
			substrs.push_back(out);
		return;
	}
	string out1{out}, out2{out};
	char c = in.at(0);
	in.erase(0, 1);
	out2 += string{c};
	get_substring(in, out1, substrs);
	get_substring(in, out2, substrs);
}

int main() {
	string in{}, out{};
	vector<string> substrs{};
	cin >> in;
	//cout << in << '\n';
	get_substring(in, out, substrs);
	// sort(substrs.begin(), substrs.end());
	for (const string& str: substrs) {
		cout << str << '\n';
	}
	return 0;
}
