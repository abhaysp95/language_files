// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void substrs(string in, string& out, vector<string>& vec_str, const string::size_type& in_size) {
	if (in.empty()) {
		return;
	}
	if (!out.empty()) {
		if ((in.size() + out.size()) == in_size) {
			// insert in ascending order
			vec_str.push_back((min(in, out)) + " " + max(in, out));
		}
	}
	string out1{out}, out2{out};
	char c = in.at(0);
	out2 += string{c};
	in.erase(0, 1); // delete first element of string
	substrs(in, out1, vec_str, in_size);
	substrs(in, out2, vec_str, in_size);
}

int main(int argc, char **argv) {
	string in{}, out{};
	cin >> in;
	vector<string> vec_str{};
	substrs(in, out, vec_str, in.size());
	cout << "Size: " << vec_str.size() << '\n';
	for (const string& str: vec_str) {
		cout << str << '\n';
	}

	// logic is to get all the substrings for string of size greater than 1 and add them with space with previous string
	/** vector<string> final_substrs{vec_str.begin(), vec_str.end()};
	for (vector<string>::iterator iter = vec_str.begin(); iter != vec_str.end(); ++iter) {
		vector<string> splits = split_string(*iter);
		for (vector<string>::iter siter = splits.begin(); siter != splits.end(); ++siter) {
			if ((*siter).size() > 1) {

			}
		}
	} */
	cout << endl;
	return 0;
}