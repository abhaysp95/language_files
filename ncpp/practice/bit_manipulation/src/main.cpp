// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_bit(int input, int pos) {
	return ((input & (1 << pos)) != 0 ? 1 : 0);
}

int set_bit(int input, int pos) {
	return (input | (1 << pos));
}

int clear_bit(int input, int pos) {
	return ((input & (~(1 << pos))));  // ~(1 << 2) means ~(0100) = 1011(1's compliment)
}

int update_bit(int input, int pos, int value) {
	// update bit is just clear_bit then set_bt
	return ((input & (~(1 << pos))) | (value << pos));
	// input: 13(1101), pos: 1, value: 1
	// clear_bit(1101 & (~(0010))) = (1101 & 1101) = 1101
	// set_bit (1101 | (1 << 1)) = (1101 | 0010) = 1111
}

void check_if_power_of_2() {
	// logic: if n is power of 2, then n & (n - 1) is always 0
	// also: n & n - 1 have every same bit as n, except rightmost set bit
	int input{};
	cin >> input;
	/* { // logic of how is done on bit level
		int temp = input;
		int pos{};
		// to make n - 1, I have to do flip every bit from the rightmost set bit upto the very right end
		// 12(1100), 11(1011)
		while (true) {
			if (get_bit(input, pos++)) {  // get pos of rightmost set bit
				break;
			}
		}
		// flip every bit upto rightmost setbit
		for (size_t i = 0; i < pos; ++i) {
			if (get_bit(input, i)) {
				temp = update_bit(temp, i, 0);
			}
			else {
				temp = update_bit(temp, i, 1);
			}
		}
		cout << "input: " << input << ", temp: " << temp << '\n';
	} */
	cout << ((input & input - 1) ? "False": "True") << endl;  // that's all you have to do
}

void number_of_1_bit() {
	// logic: given a number n(11(1011)), it's (n - 1)(10(1010)) have same bits as n except rightmost set bit
	// same for (10(1010)) and (9(1001)), now when we'll get to number like this to a number which is power of 2,
	// in this case(8), then n & n - 1 is going to be 0, and we'll count how many iterations it took to reach
	// upto number which is power of 2, that's the count of '1' bits
	int input{};
	cin >> input;
	size_t count{};
	/* {  // my approach
		while (input & (input - 1)) {
			count++;
			input--;
		}
		if (input && !count) {  // since number which is power of 2, will have only one '1' bit
			count = 1;
		}
	} */
	{  // better way to code
		while (input) {
			input = (input & (input - 1));
			count++;
		}
	}
	cout << count << endl;
}

void get_subsets() {
	string input{};
	cin >> input;
	/** logic is that from 0 upto len(string), bits position of the number
	 * represent subset
	  e.g., abc
	  ""   000
	  c    001
	  b    010
	  bc   011
	  a    100
	  ac   101
	  ab   110
	  abc  111
	*/
	for (size_t i = 0; i < (1 << input.size()); ++i) {
		for (size_t j = 0; j < input.size(); ++j) {
			// check the set bit
			if (i & (1 << j)) {
				cout << input.at(j);
			}
		}
		cout << '\n';
	}
}

void print_subsets(const string& input, size_t count, size_t bit_count) {
	if ((bit_count == input.size()) || (bit_count == count)) {
		return;
	}
	if (count & (1 << bit_count)) {  // check bits set to 1 in count
		cout << input.at(bit_count);
	}
	print_subsets(input, count, bit_count + 1);
}

void get_subsets_recursively(const string& input, size_t count) {
	if (count == (1 << input.size())) {
		return;
	}
	print_subsets(input, count, 0);
	if (count)
		cout << '\n';
	get_subsets_recursively(input, count + 1);
}

// all number except one(present one time), are present twice, find it
void find_unique_number() {
	int element{}, result{};
	while (cin >> element) {
		result ^= element;
	}
	cout << result << endl;
}

// all number except two numbers are present twice(these 2 numbers are unique), find them
void find_two_unique_numbers() {
	int element{}, result{};
	vector<int> numbers{};
	while (cin >> element) {
		numbers.push_back(element);
		result ^= element;
	}
	// now the result will have a number, whose rightmost set bit will tell
	// that either of the two unique numbers are having the same rightmost set
	// bit position(all the duplicates xor will give zero), now get all the
	// elements with same rightmost set bit position and xor them and you'll
	// get first unique number, now xor this unique number with result and
	// you'll get second unique number
	size_t res_setbit_pos{};
	for (size_t i = 0; i <= result; ++i) {
		if ((result & (1 << i)) != 0) {
			res_setbit_pos = i;
			break;
		}
	}
	/** another way to find the set_bit_pos
	int setbit{};
	while (setbit != 0) {
		setbit = result & 1;
		res_setbit_pos++;
		result >>= 1;
	} */
	int temp_res{result};
	for (vector<int>::const_iterator iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
		if (get_bit(*iter, res_setbit_pos) == 1) {
			temp_res ^= *iter;
		}
	}
	cout << temp_res << " " << (temp_res ^ result) << endl;
}

void find_unique_number2() {
	vector<int> elements{};
	int element{};
	while (cin >> element) {
		elements.push_back(element);
	}
	vector<int>::const_iterator max_elem = max_element(elements.cbegin(), elements.cend());
	cout << "max_elem: " << *max_elem << '\n';
	// get max array size
	int counter{};
	while ((1 << counter) <= *max_elem)
		counter++;
	cout << "counter: " << counter << '\n';
	size_t arr_size{static_cast<size_t>(counter)};
	int* hash_arr = new int[arr_size];
	// fill 0
	for (size_t i = 0; i < counter; ++i) {
		*(hash_arr + i) = 0;
	}
	for (size_t i = 0; i < counter; ++i) {
		for (vector<int>::const_iterator iter = elements.cbegin(); iter != elements.cend(); ++iter) {
			if ((*iter & (1 << i)) != 0) {
				*(hash_arr + i) += 1;
			}
		}
	}
	// since other than unique every element is present 3 times, so we'll mod with 3
	for (size_t i = 0; i < counter; ++i) {
		*(hash_arr + i) %= 3;
	}
	/* while (counter > 0) {
		counter--;
		cout << *(hash_arr + counter);
	} */
	int num{};
	for (size_t i = 0; i < counter; ++i) {
		if (i != 0) {
			num += (*(hash_arr + i) * (2 << (i - 1)));
		}
		else {
			num += *(hash_arr + i);
		}
	}
	cout << num << endl;
}

void find_unique_number2_better() {
	int result{};

	vector<int> elements{};
	int element{};
	while (cin >> element) {
		elements.push_back(element);
	}
	vector<int>::const_iterator max_elem = max_element(elements.cbegin(), elements.cend());
	cout << "max_elem: " << *max_elem << '\n';
	// get max array size
	size_t counter{};
	while ((1 << counter) <= *max_elem)
		counter++;
	cout << "counter: " << counter << '\n';
	size_t arr_size{counter};
	int* hash_arr = new int[arr_size];
	// fill 0
	for (size_t i = 0; i < counter; ++i) {
		*(hash_arr + i) = 0;
	}
	for (size_t i = 0; i < counter; ++i) {
		size_t sum{};
		for (vector<int>::const_iterator iter = elements.cbegin(); iter != elements.cend(); ++iter) {
			if (get_bit(*iter, i)) {
				sum++;
			}
		}

		if (sum % 3 != 0) {
			result = set_bit(result, i);
		}
	}
	cout << result << endl;
}

int main(int argc, char **argv) {
	//int input{}, pos{};
	//cin >> input >> pos;
	// cout << get_bit(input, pos) << endl;
	// cout << set_bit(input, pos) << endl;
	// cout << clear_bit(input, pos) << endl;
	// int value{};
	// cin >> value;
	// cout << update_bit(input, pos, value) << endl;
	// check_if_power_of_2();
	// number_of_1_bit();
	// get_subsets();
	/* string input{};
	cin >> input;
	get_subsets_recursively(input, 0); */
	// find_unique_number();
	// find_two_unique_numbers();
	// find_unique_number2();
	find_unique_number2_better();
	return 0;
}