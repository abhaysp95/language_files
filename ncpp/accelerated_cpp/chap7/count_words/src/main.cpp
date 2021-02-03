// main file

#include <iostream>
#include <map>
#include <string>

int main(int argc, char **argv) {
	std::map<std::string, int> counters;
	std::string temp_str;
	while (std::cin >> temp_str) {
		// when counters doesn't found the key with the element we entered, it
		// creates new key with that element automatically, and value is initialized
		// with the given _Tp type for value automatically
		++counters[temp_str];  // increment the value of counters for each word found
	}
	// counters stored the key-value pair in alphabetical order of keys
	std::map<std::string, int>::const_iterator idx = counters.begin();
	while (idx != counters.end()) {
		std::cout << "[ " << idx->first << " ]: " << idx->second << "\n";
		idx++;
	}
	std::cout << std::endl;
	return 0;
}