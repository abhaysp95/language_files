// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
	std::cout << "Enter the strings[press Ctrl-d to cancel]: " << std::endl;
	std::vector<std::string> word_list;
	std::string word;
	while (std::cin >> word) {
		word_list.push_back(word);
	}
	typedef std::string::size_type rq_size;
	rq_size max = word_list.at(0).size();
	rq_size min = max;
	for (std::string word: word_list) {
		rq_size current_word_size = word.size();
		// if it's greater than max then it can't be less than min
		if (current_word_size > max) {
			max = current_word_size;
		}
		else if (current_word_size < min) {
			min = current_word_size;
		}
	}
	std::cout << "Max: " << max << ", Min: " << min << std::endl;
	return 0;
}