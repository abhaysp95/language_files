// main file

#include <iostream>
#include <string>

using namespace std;

void remove_duplicates(string& input, string& output) {
	if (input.size() == 0)
		return;
	char c = input.at(0);
	input.erase(0, 1);
	if (c != input[0]) {
		output += c;
	}
	remove_duplicates(input, output);
}

string remove_duplicates1(string input) {
	if (input.size() == 0)
		return "";
	char c = input[0];
	string str = remove_duplicates1(input.substr(1));
	if (c == str[0])
		return str;
	return (c + str);
}

int main(int argc, char **argv) {
	string input{}, output{};
	cin >> input;
	//remove_duplicates(input, output);
	//cout << output << endl;
	cout << remove_duplicates1(input) << endl;
	return 0;
}