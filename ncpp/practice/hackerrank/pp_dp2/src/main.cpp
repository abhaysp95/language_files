// main file

#include <iostream>

using namespace std;

int get_count(int count) {
	if (count <= 0)
		return 1;
	if (count == 1)
		return get_count(count - 1);
	else if (count == 2)
		return get_count(count - 1) + get_count(count - 2);
	return get_count(count - 1) + get_count(count - 2) + get_count(count - 3);
}

int main(int argc, char **argv) {
	int num{};
	cin >> num;
	int res = get_count(num);
	cout << res << endl;
	return 0;
}