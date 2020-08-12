// demonstrating function overloading feature

#include <iostream>
#include <string>
#include <vector>

void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector<std::string>);

void print(int ic) {
	std::cout << "Got int/char: " << ic << std::endl;
}

void print(double df) {
	std::cout << "Got double/float: " << df << std::endl;
}

void print(std::string strg) {
	std::cout << "Got C/C++ style string: " << strg << std::endl;
}

void print(std::string strg1, std::string strg2) {
	std::cout << "Again got C/C++ style string: " << strg1 << " and " << strg2 << std::endl;
}

void print(std::vector<std::string> some_strings) {
	std::cout << "Strings in the vector are: " << std::endl;
	int count {};
	for (std::string strg: some_strings) {
		std::cout << strg;
		count++;
		if (count < some_strings.size()) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	print(10);
	print('A');  // get promoted to int, prints 65

	print(23.5);
	print(23.6f);  // float will get promoted to double


	std::string s{"C++ string"};
	print(s);
	// this c-style string will get promoted to std::string of C++
	print("C-style string");

	// char c[15] = "C-style string";
	char c[15] {"C-style string"};  // above one is also correct
	print(c, s);

	std::vector<std::string> three_stooges{"larry", "moe", "curly"};
	print(three_stooges);

	return 0;
}

/* only one of the prototype should be used for default arguments if you
 * give it two more than one function, and don't provide any arg at calling
 * time, the compiler will get confuse.

 * Also, overloading doesn't depend on the return type, so
 *     int print();
 *     double print();
 * doesn't matter, it's wrong
 */
