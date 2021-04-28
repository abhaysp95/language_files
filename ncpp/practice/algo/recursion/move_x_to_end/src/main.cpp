// main file

#include <iostream>
#include <string>

using namespace std;

string move_x_to_end(string input) {
	if (input.size() == 0)
		return "";
	char c = input[0];
	string str = move_x_to_end(input.substr(1));
	if (c == 'x')
		return (str + c);  // then move x to end
	return (c + str);
}

int main(int argc, char **argv) {
	string input{};
	cin >> input;
	cout << move_x_to_end(input) << endl;
	return 0;
}