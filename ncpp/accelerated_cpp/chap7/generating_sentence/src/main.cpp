// main file

#include <iostream>
#include <string>
#include <vector>

#include "../inc/gen_sen_util.hpp"

using namespace std;

int main(int argc, char **argv) {

	srand(time(0));

	Grammer grammer = read_grammer(cin);
	vector<string> gen_string = gen_sentence(grammer);

	for (const string& str: gen_string) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}