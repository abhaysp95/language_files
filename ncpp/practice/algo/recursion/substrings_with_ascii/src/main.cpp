// main file

#include <iostream>
#include <string>

using namespace std;

void substring(string input, string& out) {
	if (input.size() == 0) {
		cout << out << '\n';
		return;
	}
	char ch = input[0];
	string o1{out}, o2{out}, o3{out};
	o2 = ch + o2;
	o3 = to_string(int(ch)) + o3;
	input.erase(0, 1);
	substring(input, o1);
	substring(input, o2);
	substring(input, o3);
}

void substring1(string input, string ans) {
	if (input.length() == 0) {
		cout << ans << '\n';
		return;
	}
	char ch = input[0];
	substring1(input.substr(1), ans);
	substring1(input.substr(1), ch + ans);
	substring1(input.substr(1), to_string(int(ch)) + ans);
}

int main(int argc, char **argv) {
	string input{}, output{};
	cin >> input;
	substring1(input, output);
	return 0;
}