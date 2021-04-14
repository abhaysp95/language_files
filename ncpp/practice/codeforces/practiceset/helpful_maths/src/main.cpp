// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>
split(const string& str, const char& delim)
{
	vector<string> ret{};
	string::const_iterator first = str.cbegin();
	string::const_iterator second = str.cbegin();
	while (first != str.cend()) {
		first = find_if(first, str.cend(), [delim](const char& c) {
				return (c == delim) ? false : true;
				});
		second = find_if(first, str.cend(), [delim](const char& c) {
				return (c == delim) ? true: false;
				});
		if (first != str.cend()) {
			ret.push_back(string{first, second});
			first = second;
		}
	}
	return ret;
}

int main(int argc, char **argv) {
	vector<string> splits{};
	string input{};
	getline(cin, input);
	splits = split(input, '+');
	sort(splits.begin(), splits.end());
	string output{};
	for (vector<string>::const_iterator iter = splits.cbegin(); iter != splits.cend(); ++iter) {
		output+=*iter;
		if (iter != splits.cend() - 1) {
			output+='+';
		}
	}
	cout << output << endl;
	return 0;
}