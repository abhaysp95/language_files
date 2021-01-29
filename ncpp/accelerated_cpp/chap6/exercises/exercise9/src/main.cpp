// main file

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main(int argc, char **argv) {
	std::vector<std::string> input_strings;
	std::string temp_str;
	while (getline(std::cin, temp_str)) {
		input_strings.push_back(temp_str);
	}
	/** if you'll pass input_strings.begin() as third arugment then the return
	 * type will be an string iterator probably, not string
	 * also don't pass |""|(double inverted comma) as third argument cause it'll
	 * be const char* not std::string
	 */
	std::string final = std::accumulate(input_strings.begin(), input_strings.end(), std::string(""));
	std::cout << "Result:\n" << final << std::endl;
	return 0;
}