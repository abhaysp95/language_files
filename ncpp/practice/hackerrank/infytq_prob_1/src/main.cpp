// main file

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	string str{};
	cin >> str;
	cout << str << '\n';
	string::iterator front{str.begin()}, rear{str.end() - 1};
	while (front < rear) {
		if ((isalpha(*front)) && (isalpha(*rear))) {
			char c = *front;
			*front = *rear;
			*rear = c;
			front++;
			rear--;
		}
		else {
			if (!(isalpha(*front))) {
				front++;
			}
			if (!(isalpha(*rear))) {
				rear--;
			}
		}
	}
	cout << str << endl;
	return 0;
}

	/* string str{}, symbols{}, output{};
	cin >> str;
	//getline(cin, str)
	for (string::const_reverse_iterator iter = str.crbegin(); iter != str.crend(); ++iter) {
		if (!isalnum(*iter)) {
			output += ' ';
			symbols += *iter;
		}
		else {
			output += *iter;
		}
	}
	cout << output << '\n';
	//output.replace(output.begin() + 1, output.begin() + 2, "*");
	for (string::const_reverse_iterator iter = symbols.crbegin(); iter != symbols.crend(); ++iter) {
		string::iterator space_pos = find_if(output.begin(), output.end(), [](const char& c) {
				return isspace(c);
				});
		if (space_pos == output.end()) {
			break;
		}
		output.replace(space_pos, space_pos + 1, string{*iter});
	}
	cout << output << endl; */

		//replace_if(output.begin(), output.end(), [](const char& c) {
				//return isspace(c);
				//}, *iter);
		/* replace() is available in string while replace_if in algorithm */