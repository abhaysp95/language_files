// main file

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using count_map = map<size_t, vector<string>>;

int
is_word_found(const count_map& occurances, const string& find_word)
{
	if (occurances.empty()) {
		return -1;
	}
	count_map::const_iterator iter = occurances.begin();
	//count_map::size_type count{1};
	bool found_word = false;
	do {
		vector<string>::const_iterator iter2 = find(iter->second.begin(), iter->second.end(), find_word);
		if (iter2 != iter->second.end()) {
			found_word = true;
			break;
		}
		//count++;
		iter++;
	} while (iter != occurances.end());
	if (!found_word) {
		return -1;
	}
	return iter->first;
}

void print_occurances(const count_map& occurances) {
	cout << "Occurance_Count: [Words]\n";
	for (const pair<const size_t, vector<string> >& x: occurances) {
		cout << x.first << ": [";
		for (vector<string>::const_iterator iter = x.second.cbegin(); iter != x.second.cend(); ++iter) {
			cout << *iter;
			if (iter != x.second.cend() - 1) {
				cout << ", ";
			}
		}
		cout << "]\n";
	}
	cout << endl;
}

int main(int argc, char **argv) {
	string read_str{};
	count_map occurances{};
	while (cin >> read_str) {
		int key_pos = is_word_found(occurances, read_str);
		if (key_pos != -1) {  // word is found
			vector<string>::iterator iter2 = find(occurances[key_pos].begin(), occurances[key_pos].end(), read_str);
			occurances[key_pos].erase(iter2);
			if (occurances[key_pos].empty()) {
				occurances.erase(key_pos);
			}
			key_pos++;
			occurances[key_pos].push_back(read_str);
		}
		else {
			occurances[1].push_back(read_str);
		}
	}
	print_occurances(occurances);
	return 0;
}