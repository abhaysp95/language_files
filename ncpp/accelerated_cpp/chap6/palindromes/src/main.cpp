// main file

#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& str);

int main(int argc, char **argv) {
	std::string str;
	std::cin >> str;
	std::cout << (is_palindrome(str) ? "yes" : "no") << std::endl;
	return 0;
}

bool is_palindrome(const std::string& str) {
	/** rbegin() startes from the right side of container and marches backwards
	  first two iterators passed specify first sequence and last one specifies
	  second sequence. equal() function assumes that second sequence is of the
	  same size as first that's why it doesn't need end iterator.
	  Now the equal() function will compare starting elements one by one of first
	  sequence and first element from second sequence(which is actually last
	  element of string).
	  */
	return std::equal(str.begin(), str.end(), str.rbegin());
}