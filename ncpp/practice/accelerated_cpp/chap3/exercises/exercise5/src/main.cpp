// main file

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

int main(int argc, char **argv) {
	std::string name;
	size_t num_homework{5};
	std::vector<std::string> name_list;
	std::vector<double> mean_score_list;
	typedef std::string::size_type str_size;
	std::cout << "Enter the name: ";
	while (std::cin >> name) {
		str_size count{0};
		while ((count++ < name.size() - 1)) {
			if (!std::isalnum(name.at(count))) {
				std::cout << "Name should be in alphanumeric format" << std::endl;
				return 1;
			}
		}
		name_list.push_back(name);
		std::cout << "Enter all the homework score of " << num_homework << " subjects for " << name << ": " << std::endl;
		// or to use just array you have to provide iterator to sort
		// so then use, std::begin(<array_name>) and std::end(<array_name>)
		std::array<double, 5> all_marks{0};
		for (size_t i = 0; i < num_homework; ++i) {
			std::cin >> all_marks[i];
		}
		// since sort takes iterator provide them iterator
		std::sort(all_marks.begin(), all_marks.end());
		double median = num_homework % 2 == 0
			? (all_marks[num_homework / 2] + all_marks[num_homework / 2 - 1]) / 2
			: all_marks[num_homework / 2];
		mean_score_list.push_back(median);
		std::cout << std::endl << "All marks entered successfully";
		std::cout << std::endl << "Enter another students name and marks[or press Ctrl-d to exit]" << std::endl;
	}
	std::cout << std::endl << "Final result: " << std::endl;
	for (size_t i = 0; i < name_list.size(); ++i) {
		std::cout << "Name: " << name_list.at(i) << ", Score: " << mean_score_list.at(i) << std::endl;
	}
	return 0;
}