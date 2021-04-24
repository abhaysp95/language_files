// main file

#include <iostream>
#include <vector>

using namespace std;

size_t get_max_profit(const vector<size_t>& vlarr, const vector<size_t>& wtarr, size_t bc, size_t count) {
	if (bc == 0 || count == 0) {
		return 0;
	}
	if (wtarr.at(count - 1) > bc) {
		// since weight of item is more than that of bag, we can't take this item
		return get_max_profit(vlarr, wtarr, bc, count - 1);
	}
	return max(vlarr.at(count - 1) + get_max_profit(vlarr, wtarr, bc - wtarr.at(count - 1), count - 1),
			get_max_profit(vlarr, wtarr, bc, count - 1));
}

int main(int argc, char **argv) {
	size_t bc{};
	size_t count{};
	vector<size_t> wtarr{};
	vector<size_t> vlarr{};
	//wtarr.reserve(count);
	//vlarr.reserve(count);
	cin >> bc >> count;
	size_t element{};
	for (size_t i = 0; i < count; ++i) {
		cin >> element;
		wtarr.push_back(element);
	}
	for (size_t i = 0; i < count; ++i) {
		cin >> element;
		vlarr.push_back(element);
	}
	size_t res_val = get_max_profit(vlarr, wtarr, bc, count);
	cout << res_val << endl;
	return 0;
}