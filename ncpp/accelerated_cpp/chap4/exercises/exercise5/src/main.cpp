// main file

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>

int main(int argc, char **argv) {
	std::string word;
	std::vector<std::string> words;
	std::cin >> word;
	std::string::size_type max_len{0};
	while (std::cin >> word) {
		words.push_back(word);
		max_len = std::max(max_len, word.size());  // get len of max len word
	}
	std::cout << "total words entered: " << words.size() << std::endl;
	// make set from vector
	std::set<std::string> words_list(words.begin(), words.end());
	// print each word cout
	for (std::string word: words_list) {
		size_t count_is = std::count(words.begin(), words.end(), word);
		std::cout << word << std::setw(max_len + (max_len - word.size())) << count_is << std::endl;
	}
	return 0;
}