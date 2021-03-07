// cpp file for "demo_util.hpp"

#include "../inc/demo_util.hpp"

#include <algorithm>
#include <iostream>

void biggies(vec_str& words, const vec_str::size_type sz) {
	// put words in alphabetical order and remove duplicates
	elimDups(words);
	// resort by length, maintaing alphabetical order among words of same length
	//std::stable_sort(words.cbegin(), words.cend(), isShorter);
	// lambda way to write stable_sort
	std::stable_sort(words.cbegin(), words.cend(),
			[](const std::string& word1, const std::string& word2)
				{ return word1.size() < word2.size(); });
	// get an iterator to the first element whose size is >= sz
	// compute the number of elements with size >= sz
	// prints words of given length or greater, space seperated
	vec_str::const_iterator wc = std::find_if(words.cbegin(), words.cend(),
			[sz](const std::string& word)
				{ return word.size() >= sz; });
	vec_str::size_type count = words.cend() - wc;
	std::cout << count << " " << make_plural(sz, "word", "s") << " of length " << sz << " or longer " << std::endl;
}

void elimDups(vec_str& words) {
	// first sort the words(in lexographical order)
	std::sort(words.begin(), words.end());
	// remove duplicates
	vec_str::iterator temp_iter = std::unique(words.begin(), words.end());
	// free up the space
	words.erase(temp_iter, words.end());
}

bool isShorter(const std::string& word1, const std::string& word2) {
	return word1.size() < word2.size();
}

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending) {
	return (ctr > 1 ? word + ending : word);
}