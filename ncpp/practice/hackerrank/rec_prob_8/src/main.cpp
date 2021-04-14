// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void substrs(string in, string& out, vector<string>& vec_str, const size_t& in_length) {
	if (in.empty()) {
		if (!out.empty()) {
			if (out.at(0) != ' ') {
				size_t count = 0;
				for (string::const_iterator iter = out.cbegin(); iter != out.cend(); ++iter) {
					if (*iter != ' ') {
						count++;
					}
				}
				if (count == in_length) {
					vec_str.push_back(out);
				}
			}
		}
		return;
	}
	string out1{out}, out2{out};
	char c = in.at(0);
	out1 += " " + string{c};
	out2 += string{c};
	in.erase(0, 1); // delete first element of string
	substrs(in, out1, vec_str, in_length);
	substrs(in, out2, vec_str, in_length);
}

int main(int argc, char **argv) {
	string in{}, out{};
	cin >> in;
	vector<string> vec_str{};
	substrs(in, out, vec_str, in.size());
	cout << "Size: " << vec_str.size() << '\n';
	sort(vec_str.begin(), vec_str.end(), [](const string& str1, const string& str2) {
			return str1 > str2;
			});
	for (const string& str: vec_str) {
		cout << str << '\n';
	}
	cout << endl;
	return 0;
}