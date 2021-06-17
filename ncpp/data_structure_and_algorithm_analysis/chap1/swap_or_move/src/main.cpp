// main file

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap1(vector<string>& x, vector<string>& y) {
	vector<string> tmp = x;
	x = y;
	y = tmp;
}

void swap2(vector<string>& x, vector<string>& y) {
	vector<string> tmp = static_cast<vector<string> &&>(x);
	x = static_cast<vector<string> &&>(y);
	y = static_cast<vector<string> &&>(tmp);
}

void swap3(vector<string>& x, vector<string>& y) {
	vector<string> tmp = move(x);
	x = move(y);
	y = move(tmp);
}

int main(int argc, char **argv) {
	vector<string> vec_str1{}, vec_str2{};
	string str{};
	while (cin >> str) {
		vec_str1.push_back(str);
		cin >> str;
		vec_str2.push_back(str);
	}
	// swap3(vec_str1, vec_str2);
	// swap(vec_str1, vec_str2);  default std::swap()
	for (const string& str: vec_str1) {
		cout << str << '\n';
	}
	cout << "----------------" << '\n';
	for (const string& str: vec_str2) {
		cout << str << '\n';
	}
	cout << endl;
	return 0;
}


// feed some big file(like log file) to check the performance