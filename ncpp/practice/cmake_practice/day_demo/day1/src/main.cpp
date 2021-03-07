// main file

#include <iostream>
#include <fstream>
#include <vector>

int get_result_two(const std::vector<size_t>& inputs) {
	std::vector<size_t>::const_iterator primary, secondary;
	for (primary = inputs.begin(); primary != inputs.end() - 1; ++primary) {
		for (secondary = primary + 1; secondary != inputs.end(); ++secondary) {
			if (*primary + *secondary == 2020) {
				std::cout << "primary: " << *primary << ", secondary: " << *secondary
					<< ", result: " << (*primary) * (*secondary) << "\n";
			}
		}
	}
	return 0;
}

// using this one
long get_instant_result_two(const std::vector<size_t>& inputs, size_t num, std::ifstream& in) {
	long result{};
	bool result_found = false;
	std::vector<size_t>::const_iterator citer;
	for (citer = inputs.begin(); citer != inputs.end() && !result_found; ++citer) {
		if (*citer + num == 2020) {
			result = *citer * num;
			result_found = true;
			in.close();
		}
	}
	return result;
}

long get_instant_result_three(const std::vector<size_t>& inputs, size_t num, std::ifstream& in) {
	long result{};
	bool result_found = false;
	std::vector<size_t>::const_iterator first, second;
	for (first = inputs.begin(); first != inputs.end() - 1 && !result_found; ++first) {
		for (second = first + 1; second != inputs.end() && !result_found; ++second) {
			if ((*first) + (*second) + num == 2020) {
				result = (*first) * (*second) * num;
				result_found = !result_found;
				in.close();
			}
		}
	}
	return result;
}

int main(int argc, char **argv) {
	// open input file
	std::ifstream inputs;
	inputs.open("./input_main.txt");
	std::vector<size_t> input_values;
	std::vector<size_t>::size_type input_size = input_values.size();
	size_t value;
	//while (inputs >> value) {
		//input_values.push_back(value);
	//}
	//get_result(input_values);
	long result{};
	while (inputs >> value) {
		// for two, make the comparision < 1
		if (input_size++ < 2) {
			input_values.push_back(value);
			continue;
		}
		//result = get_instant_result_two(input_values, value, inputs);
		result = get_instant_result_three(input_values, value, inputs);
		if (result == 2020) {
			break;
		}
		input_values.push_back(value);
	}
	std::cout << "result: " << result << std::endl;
	if (inputs.is_open()) {
		inputs.close();
	}
	return 0;
}