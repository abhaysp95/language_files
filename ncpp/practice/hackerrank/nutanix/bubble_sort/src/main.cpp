// main file

#include <iostream>
#include <limits>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split_string(std::string input_string);
void countswap(std::vector<int> a);

int main(int argc, char **argv) {
	size_t n;
	std::cin >> n;
	// ignore to ignore the given char in given count
	// numeric_limits to get numeric limit for different types
	// streamsize represents size and char counts in stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string a_temp_temp;
	getline(std::cin, a_temp_temp);
	std::vector<std::string> a_temp = split_string(a_temp_temp);

	std::vector<int> a(n);

	for (size_t i = 0; i < n; ++i) {
		int a_item = std::stoi(a_temp[i]);
		a[i] = a_item;
	}

	countswap(a);
	for (const int& num: a) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;

	return 0;
}

std::vector<std::string> split_string(std::string input_string) {
	// removes consecutive duplicate elements and returns the last position after removing
	// example = {1, 2, 1, 1, 3, 3, 3, 4, 5, 4};
	// performing unique action to above array will give
	// {1, 2, 1, 3, 4, 5, 4, x, x, x};  x is blank(indeterminate),
	// return is first x
	// if you apply sort on this
	// {1, 1, 2, 3, 4, 4, 5};
	// apply unique once again
	// {1, 2, 3, 4, 5, x, x}
	std::string::iterator new_end = std::unique
		(input_string.begin(), input_string.end(), [] (const char& x, const char& y) {
		 return x == y and x == ' ';
		 });
	// std::unique is mostly followed by erase as well(this'll delete all x)
	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	std::vector<std::string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);
	while (pos != std::string::npos) {
		splits.push_back(input_string.substr(i, pos - i));
		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}
	splits.push_back(input_string.substr(i, std::min(pos, input_string.length()) - i + 1));
	return splits;
}

void countswap(std::vector<int> a) {
	size_t count = 0;
	for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < a.size() - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				a[j] += a[j + 1];
				a[j + 1] = a[j] - a[j + 1];
				a[j] -= a[j + 1];
				count++;
			}
		}
	}
	std::cout << "Array is sorted in " << count << " swaps.\n";
	std::cout << "First Element: " << a.at(0);
	std::cout << "\nLast Element: " << a.at(a.size() - 1) << std::endl;
}