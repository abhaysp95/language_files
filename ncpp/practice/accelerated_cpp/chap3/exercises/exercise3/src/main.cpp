// WAP to tell the count of each time a distinct word appers from input

// main file

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

int main(int argc, char **argv) {
	std::cout << "Give work one by one[press Ctrl-d to cancel]: " << std::endl;


	/*{  // using set(working)
		std::set<std::string> word_list;
		std::string word;
		while (std::cin >> word) {
			word_list.insert(word);
		}
		std::cout << std::endl;
		std::cout << "distinct count: " << word_list.size() << std::endl;
	}*/




	{  // using vector with find with iterator(working)
		std::vector<std::string> word_list;
		std::vector<std::string>::iterator it;
		std::string word;
		while (std::cin >> word) {
			word_list.push_back(word);
		}
		for (size_t i = 0; i < word_list.size(); ++i) {
			it = std::find(word_list.begin(), word_list.end(), word_list.at(i));
			if (it != word_list.end()) {
				size_t pos = it - word_list.begin();  // making it a number from iterator
				if (pos < i) {
					word_list.erase(word_list.begin() + i);  // takes an iterator
				}
			}
		}
		std::cout << std::endl;
		std::cout << "distinct count: " << word_list.size() << std::endl;
	}




	/*{  // using vector with find with iterator(2nd way)
		std::vector<std::string> word_list;
		std::string word;
		std::cin >> word;
		if (!std::cin) {
			std::cout << "Enter few words" << std::endl;
			return 1;
		}
		word_list.push_back(word);
		while (std::cin >> word) {
			// why this if condition fails every time, on debugging it seems
			// that end() is giving some error
			if (std::find(word_list.begin(), word_list.end(), word) != word_list.end()) {
				// I simply want if word is not already in word_list, it should
				// be entered in word_list
				word_list.push_back(word);
			}
		}
		std::cout << std::endl;
		std::cout << "distinct count: " << word_list.size() << std::endl;
	}*/


	return 0;
}