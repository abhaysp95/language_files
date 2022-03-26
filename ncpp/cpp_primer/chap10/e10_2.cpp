#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main() {
	list<string> lst{"this", "is", "a", "demo", "of", "a", "function"};
	size_t count = std::count(begin(lst), end(lst), "a");
	cout << "count of 'a': " << count << endl;
}
