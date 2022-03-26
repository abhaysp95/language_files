// main file

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

void get_strs(string in, string& out, vector<string>& tot_strs) {
	if (in.empty()) {
		if (!out.empty()) {
			cout << out << '\n';
			vector<string>::iterator find_char = find(tot_strs.begin(), tot_strs.end(), out);
			if (find_char == tot_strs.end()) {
				tot_strs.push_back(out);
			}
		}
		return;
	}
	char c = in.at(0);
	string out1{out}, out2{out};
	if (!isalpha(c)) {
		out1 += to_string(c - 48);
		out2 += to_string(c - 48);
	}
	else {
		out1 += c;
		out2 += toupper(c);
	}
	in.erase(0, 1);
	get_strs(in, out1, tot_strs);
	get_strs(in, out2, tot_strs);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string in{}, out{};
	vector<string> tot_strs{};
	cin >> in;
	get_strs(in, out, tot_strs);
	cout << "-----------------------------------" << '\n';
	for (const string& str: tot_strs) {
		cout << str << '\n';
	}
	cout << endl;
	return 0;
}