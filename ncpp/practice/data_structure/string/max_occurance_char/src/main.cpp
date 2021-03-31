// main file

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	string str{};
	cin >> str;

	// sort the string
	sort(str.begin(), str.end());

	/* {  // one way
		size_t count{};
		size_t temp_count{};

		for (string::size_type i = 0; i < str.size() - 1; ++i) {
			if (str.at(i) != str.at(i + 1)) {
				count = max(count, temp_count);
				temp_count = 0;
			}
			else {
				temp_count++;
			}
		}

		cout << "Max frequency: " << (count + 1) << '\n';
	} */

	{ // another way
		vector<size_t> count_vec(26, 0);  // size, fill 0
		for (const char& chr: str) {
			count_vec.at(chr - 97)++;
		}

		size_t max_freq = 0;
		for (const size_t& freq: count_vec) {
			max_freq = max(max_freq, freq);
		}

		cout << "Max frequency: " << max_freq << '\n';
	}

	return 0;
}