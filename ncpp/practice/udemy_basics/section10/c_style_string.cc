// some ways to use c-style string

#include <iostream>

#include <cctype>  // different functions for condition checkings/change single char(character based functions)

#include <cstring>  // for c like string behaviour, rely on null character
// some features include, copying, concatenation, search, comparision and others

using std::cin;
using std::cout;
using std::endl;

int main() {
	char c;
	cout << "Enter the character: ";
	cin >> c;

	// these are used for condition checking but I'm just printing them
	cout << "isalpha: " << isalpha(c) << endl;
	cout << "isalnum: " << isalnum(c) << endl;
	cout << "islower: " << islower(c) << endl;
	cout << "isupper: " << isupper(c) << endl;
	cout << "isdigit: " << isdigit(c) << endl;
	cout << "isprint: " << isprint(c) << endl;
	cout << "ispunct: " << ispunct(c) << endl;
	cout << "isspace: " << isspace(c) << endl;

	// see, it's for condition checking
	if (islower(c)) {
		cout << "toupper: " << toupper(c) << endl;  // these tolower() and toupper() change the case(ascii code)
	}
	else {
		cout << "tolower: " << tolower(c) << endl;
	}


	cout << "\nMoving Ahead" << endl;
	cout << "-------------------------------------" << endl;

	char my_name [15] {"JOEY"};  // this is ok
	// char my_name [8];
	// my_name = "JOE";  // this is not, can't assign address to another address

	char your_name [15];
	strcpy (your_name, "CHANDLER");  // this is ok

	cout << "My name: " << my_name << endl;
	cout << "Your name: " << your_name << endl;

	strcat (my_name, " TRIBBIANI");
	strcat (your_name, " BING");

	cout << "Again: " << endl;
	cout << "My name: " << my_name << endl;
	cout << "Your name: " << your_name << endl;

	cout << "Who has bigger?" << endl;
	// strcmp will return 0, if both the strings are same otherwise, it'll return -/+ number
	if (strcmp (your_name, my_name)) {
		cout << "I have bigger" << endl;
		cout << "And len is " << strlen(my_name) << endl;
	}
	else {
		cout << "Shit! You won" << endl;
		cout << "And len is " << strlen(my_name) << endl;
	}

	cout << "----------------------------------" << endl;
	char just_checking[30] {};
	cout << just_checking << endl;  // blank newline
	cout << strlen(just_checking) << endl;  // 0

	strcpy (just_checking, my_name);
	cout << just_checking << endl;  // string
	cout << strlen(just_checking) << endl;  // 14

	return 0;
}
