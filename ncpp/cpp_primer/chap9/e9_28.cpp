#include <iostream>
#include <forward_list>
#include <string>
#include <iterator>

using namespace std;

using mylst = forward_list<string>;

void update_list(mylst& flst, const string& f, const string& a) {
	mylst::iterator idx{flst.begin()}, prev{flst.before_begin()};
	while(idx != flst.end()) {
		if(*idx == f) break;
		prev = idx;
		idx++;
	}
	if(idx != flst.end()) {  // element found
		flst.insert_after(idx, a);
	}
	else {
		flst.insert_after(prev, a);
	}
}

int main() {
	mylst mlst = {"this", "is", "a", "forward", "list"};
	update_list(mlst, "forward", "cpp");
	copy(mlst.begin(), mlst.end(), ostream_iterator<string>(cout, ", "));
	return 0;
}
