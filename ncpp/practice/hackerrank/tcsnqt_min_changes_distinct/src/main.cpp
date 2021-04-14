// main file

#include <iostream>
#include <string>
#include <map>

using namespace std;

using tmap = map<char, size_t>;

void fill_char_counts(tmap& fmap, const string& fstr) {
	// this only filled up the strings
	for (string::const_iterator citer = fstr.cbegin(); citer != fstr.cend(); ++citer) {
		tmap::iterator find_char = fmap.find(*citer);
		if (find_char != fmap.end()) {
			fmap[*citer]++;
		}
		else {
			fmap[*citer] = 1;
		}
	}
	// now fill up rest of the chars left from the total of 26 to map
	for (char c = 'a'; c <= 'z'; ++c) {
		tmap::iterator find_char = fmap.find(c);
		if (find_char == fmap.end()) {
			fmap[c] = 0;
		}
	}
}

int main(int argc, char **argv) {
	string input{};
	cin >> input;
	cout << "input: " << input << '\n';
	tmap char_counts{};
	// fill the map
	fill_char_counts(char_counts, input);
	size_t count{};
	for (string::iterator iter = input.begin(); iter != input.end(); ++iter) {
		if (char_counts[*iter] > 1) {
			// then find the first key having value of 0
			char empty_char{};
			for (pair<const char, size_t>& p: char_counts) {
				if (p.second == 0) {
					empty_char = p.first;
					p.second = 1;  // update it as it's going to be used
					break;
				}
			}
			char_counts[*iter]--;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}