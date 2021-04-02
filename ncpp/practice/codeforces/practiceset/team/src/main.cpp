// main file

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	size_t q_num{};
	cin >> q_num;
	size_t count{};
	for (size_t i = 0; i < q_num; ++i) {
		size_t temp_count{};
		for (size_t j = 0; j < 3; ++j) {
			unsigned short temp{};
			cin >> temp;
			temp == 1 ? temp_count++ : 0;
		}
		temp_count > 1 ? count++ : 0;
	}
	cout << count << endl;
	return 0;
}