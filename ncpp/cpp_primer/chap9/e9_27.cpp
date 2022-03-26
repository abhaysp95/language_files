#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

int main() {
	using mylist = forward_list<int>;
	mylist flst{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	mylist::iterator curr = flst.begin(), prev = flst.before_begin();
	while(curr != flst.end()) {
		if(*curr % 2) {  // odd element
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;
			curr++;
		}
	}
	copy(flst.begin(), flst.end(), ostream_iterator<int>(cout, ", "));
	return 0;
}
