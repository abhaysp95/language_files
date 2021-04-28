// main file

#include <iostream>
#include <string>

using namespace std;

void replace_with_pi(string& input, string& output) {
	if (input.size() == 0)
		return;
	if (input[0] == 'p' && input[1] == 'i') {
		output += "3.14";
		input = input.substr(2);
		// to send input.substr(2) directly to function, the function should
		// have rvalue signature(but then it'll not work, because of first
		// function call, you can try having non-reference string though)
		replace_with_pi(input, output);
	}
	else {
		output += input[0];
		input = input.substr(1);
		replace_with_pi(input, output);
	}
}

int main(int argc, char **argv) {
	string input{}, output{};
	cin >> input;
	replace_with_pi(input, output);
	cout << "output: " << output << endl;
	return 0;
}