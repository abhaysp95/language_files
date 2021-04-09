// main file

#include <iostream>
#include <map>
#include <cassert>

using namespace std;

int main(int argc, char **argv) {
	size_t count{};
	cin >> count;
	map<long, size_t> occurance_table{};
	long value{};
	while (cin >> value) {
		map<long, size_t>::iterator find_value = occurance_table.find(value);
		if (find_value != occurance_table.end()) {
			find_value->second++;
		}
		else {
			occurance_table[value] = 1;
		}
	}
	for (const pair<const long, size_t>& p: occurance_table) {
		// cout << p.first << ": " << p.second << '\n';
		if (p.second != 3) {
			cout << p.first << endl;
		}
	}
	return 0;
}