// main file

#include <iostream>
#include <array>
#include <vector>
#define SIZE 100000

struct TestCase{
	size_t tc_count{};
	size_t num_of_days{};
	std::array<size_t, SIZE> nop{};  // number of peoples visited
	size_t num_record_breaking_days{};
};

void get_record_breaking_days(std::vector<TestCase>& tc_inputs);
void print_result(const std::vector<TestCase>& tc_inputs);

int main(int argc, char **argv) {
	std::cout << "Enter test case count: ";
	size_t tccount;
	std::cin >> tccount;
	std::vector<TestCase> tc_inputs{};
	TestCase democase{};

	// take inputs
	for (size_t i = 0; i < tccount; ++i) {
		democase.tc_count = i + 1;
		std::cout << (i + 1) << ": Enter number of days: ";
		std::cin >> democase.num_of_days;
		std::cout << (i + 1) << ": Enter number of persons: ";
		for (size_t j = 0; j < democase.num_of_days; ++j) {
			std::cin >> democase.nop[j];
		}
		std::cout << "\n";
		tc_inputs.push_back(democase);
	}
	get_record_breaking_days(tc_inputs);
	print_result(tc_inputs);
	return 0;
}


/**
  Condition for record breaking day:
  1) No. of visitors on a day is strictly larger than the number of visitors on
  each of the previous day
  2) Either it is the last day, or the number of visitors on the day is strictly
  larger than the number of visitors on the following day
  Note: The very first day could be a record breaking day
  */

void get_record_breaking_days(std::vector<TestCase>& tc_inputs) {
	for (TestCase& tc: tc_inputs) {
		if (tc.num_of_days == 1) {
			tc.num_record_breaking_days++;  // since it is the last day too
		}
		// 7 2 8 9
		else {  // if there are more than one day
			size_t max_people = tc.nop[0];
			for (size_t idx = 0; idx < tc.num_of_days; ++idx) {
				// check first condition
				bool conditions_passed = true;
				if (idx != 0) {  // if it isn't first day
					if (tc.nop[idx] > max_people) {
						max_people = std::max(max_people, tc.nop[idx]);
					}
					else {
						conditions_passed = false;
					}
				}
				if (conditions_passed) {
					// check second condition now
					if (idx != tc.num_of_days - 1) {  // if it isn't last day
						if (tc.nop[idx] <= tc.nop[idx + 1]) {
							conditions_passed = false;
						}
					}
				}
				if (conditions_passed) {
					tc.num_record_breaking_days++;
				}
			}
		}
	}
}

void print_result(const std::vector<TestCase>& tc_inputs) {
	std::cout << "\n----------------------\n\n";
	for (const TestCase& tempinput: tc_inputs) {
		std::cout << tempinput.tc_count << ": " << "[";
		for (size_t i = 0; i < tempinput.num_of_days; ++i) {
			std::cout << tempinput.nop[i];
			if (i < tempinput.num_of_days - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
		std::cout << "no. of record breaking days: " << tempinput.num_record_breaking_days << "\n";
		std::cout << std::endl;
	}
}