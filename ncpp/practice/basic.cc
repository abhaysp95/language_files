// a basic cpp program

#include <iostream>

using namespace std;

int main() {
	printf("Showing");
	cout << "basic usage of string in C++" << endl;
	string name = "Abhay Shanker Pathak";
	cout << "Entered name is " << name << endl;
	int first_space = name.find(' ', 0);
	cout << "Got first space at " << first_space << endl;
	string first_name;
	for (int i = 0; i < first_space; i++) {
		first_name = first_name + name[i];
	}
	cout << "First name is " << first_name << "\n";
	cout << "Getting second name with substr\n";
	int second_space = name.find(' ', first_space);
	cout << "Got second space at " << second_space << endl;
	string second_name = name.substr(first_space + 1, second_space);
	cout << "Second name is " << second_name << endl;
	cout << "Length of name " << name << " is " << name.length() << endl;
	return 0;
}
