// using range feature of for loop

#include <iostream>
#include <vector>
#include <iomanip>  // for io formatting

using std::cout;
using std::endl;
using std::vector;
using std::fixed;
using std::setprecision;

int main() {
	vector<double> temps {83.7, 243, 239.23 , 193.8, 123.4};

	double average_temp{};
	double sum{};

	for (double temp: temps) {  // you can just use "auto" for data type
		sum += temp;
	}

	average_temp = sum / temps.size();
	cout << "Sum of temps: " << sum << endl;
	cout << fixed << setprecision(2);
	cout << "Average is: " << average_temp << endl;

	// replace space with tabs
	for (char c: "This is a line") {
		// know the difference between using single and double quotes
		if (c == ' ') {
			cout << "\t";
		}
		else {
			cout << c;
		}
	}
	cout << endl;

	return 0;
}

/* we can just as well provide a array to for range, like for (auto num: [1, 23, 456, 78910]) {} */
