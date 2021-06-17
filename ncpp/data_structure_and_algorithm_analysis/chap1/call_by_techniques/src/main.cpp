// main file

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const string& randomItem(const vector<string>& vec) {
	size_t&& rand_num = rand();
	vector<string>::size_type&& vec_size = vec.size() - 1;
	return vec.at(rand_num - (rand_num / vec_size) * vec_size);
}

string& randomItem(vector<string>&& vec) {
	size_t&& rand_num = rand();
	vector<string>::size_type&& vec_size = vec.size() - 1;
	return vec.at(rand_num - (rand_num / vec_size) * vec_size);
}

int main(int argc, char **argv) {
	srand(time(0));
	vector<string> v{"hello", "world!", "this", "is", "your", "host"};
	cout << randomItem(v) << '\n';
	cout << randomItem(
			{"hello", "world!", "this", "is", "your", "host"}
			) << endl;
	return 0;
}