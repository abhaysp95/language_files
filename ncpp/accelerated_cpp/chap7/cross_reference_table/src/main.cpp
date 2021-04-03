// main file

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../inc/cross_ref_util.hpp"

using namespace std;

int main(int argc, char **argv) {
	map<string, vector<size_t> > cross_ref_table{};
	cross_ref_table = xref(cin);  // by default split will be called
	for (pair<const string, vector<size_t> >& p: cross_ref_table) {
		cout << "[ " << p.first << " ]: ";
		vector<size_t>::const_iterator citer = p.second.cbegin();
		cout << *citer;
		citer++;
		while (citer != p.second.cend()) {
			cout << ", " << *citer;
			citer++;
		}
		cout << '\n';
	}
	return 0;
}