// demonstrating C++ style string usage

#include <iostream>
#include <string>  // is in standard namespace
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::find;
using std::boolalpha;

int main() {
	// some ways to declare and initialize C++ strings
	// string is class, and s1, s2 etc. are object
	string s1;  // empty
	string s2 {"Frank"};  // Frank
	string s3 {s2};  // Frank
	string s4 {"Frank", 3};  // Fra
	string s5 {s3, 1, 4};  // ran
	string s6 (3, 'X');  // XXX, initialize with specific number of specific char
	// uses constructor style initialization

	// C++ string suppors assignment unlike C strings
	s2 = s1;  // valid
	// compound assignment will work too, like s2 += s1;

	// swap the string
	s6.swap(s1);

	string part1 {"C++"};
	string part2 {"is very nice"};
	string sentence;

	sentence = part1 + " " + part2 + " " + " language";
	cout << sentence << endl;

	// insert
	string s7 {" the"};
	string s8 {"is the good"};

	// sentence = "C++" + " is nice";  // invalid, cause it's C-style literals and can't be concatenated
	part2.insert(2, s7);
	cout << "Part2 after insertion: " << part2 << endl;
	part2.erase(2, 4);
	part2.insert(2, s8, 4, 3);
	cout << "Part2 after insertion: " << part2 << endl;

	// we can use substring and at() with string too

	// lets print something
	cout << "In char" << endl;
	for (char c: s3) {
		cout << c << endl;
	}

	cout << "\nIn int" << endl;
	cout << "----------" << endl;
	for (int d: s3) {
		cout << d << endl;
	}

	// can do comparision with comparision operators(=, >, < etc.)(lexographic comparision)
	// if not those are two C string literals
	// if two std::string object
	// is std:;string object and C style string literal
	// is std:;string object and C style string variable
	// this comparision returns bool value(true or false)

	cout << boolalpha;  // to change comparision(0, other_num) to 'True' and 'False'
	cout << s4 << "==" << s5 << ": " << (s4 == s5) << endl;  // 0

	// starting index and characters to include
	string part2_substring = part2.substr(3, 8);  // very nic

	// returns index
	short find_very = part2.find("very");  // will return the starting index of "very"
	short find_ry = part2.find("ry", 2, 8);  // look after 0,1,2 char upto 7
	short find_xxx = part2.find("XXX");  // std::nopos  , no position information available
	// rfind() is opposite of find() starts searching from backward

	part2.erase(3, 5);
	cout << part2 << endl;
	s6.clear();  // clears whole string

	cout << "part2 length is: " << part2.length() << endl;

	cout << "Input and output with C++ string" << endl;
	cout << "------------------------------------------" << endl;

	string get_name;
	cin >> get_name;  // will stop as soon as it gets ' '(space)
	cout << "Entered name: " << get_name << endl;

	// meet getline, it stops when get 'newline' char
	string get_full_name;
	getline(cin, get_full_name);
	cout << "Entered name: " << get_full_name << endl;
	cout << endl;

	string delim_is_x;
	getline(cin, delim_is_x, 'x');  // stops as soon as finds 'x' in input
	cout << "Delim input with getline(): " << delim_is_x << endl;
	cout << endl;

	return 0;
}

/* C_str() converts a C++ string to C string, returns a pointer to char constant
 * first char of C string is equivalent to the contents of C++ string
 */
