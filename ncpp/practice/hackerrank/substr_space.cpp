#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str{};
	vector<string> vec_str{};
	cin >> str;
	size_t space_pos{str.size() - 1};
	while (space_pos > 0) {
		string temp{str};
		vec_str.push_back(temp.insert(space_pos--, " "));
	}
	for (string::size_type i = str.size(); i > 0; --i) {
		str.insert(i, " ");
	}
	vec_str.push_back(str);
	for (const string& s: vec_str) {
		cout << s << '\n';
	}
	cout << endl;
}
