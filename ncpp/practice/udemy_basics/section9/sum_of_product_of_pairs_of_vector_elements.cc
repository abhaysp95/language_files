// get the sum of the product of all the pairs of the vector elements


#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> vec {};
	signed short num {};

	cin >> num;
	while (num != -1) {
		vec.push_back(num);
		cin >> num;
	};

	int sum {};

	for (int i {}; i < vec.size(); ++i) {
		for (int j {i + 1}; j < vec.size(); ++j) {
			cout << "pairs: (" << vec.at(i) << ", " << vec.at(j) << ")" << endl;
			sum += (vec.at(i) * vec.at(j));
		}
	}

	cout << vec.size() << endl;
	cout << "Sum is: " << sum << endl;
	return 0;
}
