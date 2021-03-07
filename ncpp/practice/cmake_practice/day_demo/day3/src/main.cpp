// main file

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../inc/day3_util.hpp"

long get_result(const vec_str& forest, vec_str& temp_forest);
long multiplication_result(const std::vector<size_t>& vec);
void reset_values(const vec_str& forest, vec_str& temp_forest, vec_str_iter& forest_iter, str_size& pos_col);

int main(int argc, char **argv) {
	std::ifstream input_file;
	input_file.open("./input_main.txt");
	std::string tree_row;
	vec_str forest;
	while (getline(input_file, tree_row)) {
		forest.push_back(tree_row);
	}
	input_file.close();
	/** making a temp_forest is necessary, since in case 2 you have to use forest
	  5 times, and it'll change the forest, so you have to fix it again and again */
	vec_str temp_forest;
	temp_forest.insert(temp_forest.end(), forest.begin(), forest.end());
	/**  Use this block for first part, nothing else, and comment out the two lines
	  below this block(this line too)
	str_size pos_col{};
	vec_str_iter forest_iter = forest.begin();
	std::cout << count_of_tree_encountered(forest, forest_iter, pos_col, 1, 2, 0);
	*/
	long result = get_result(forest, temp_forest);
	std::cout << "total result, part2: " << result << std::endl;
	return 0;
}

long get_result(const vec_str& forest, vec_str& temp_forest) {
	std::vector<size_t>tree_encounters_count;
	str_size pos_col{};
	vec_str_iter temp_forest_iter = temp_forest.begin();
	/** let's get all the value asked in question
	  * the three integers(size_t) in last are: right, down and tree_count
	*/
	tree_encounters_count.push_back(count_of_tree_encountered(temp_forest, temp_forest_iter, pos_col, 1, 1, 0));
	reset_values(forest, temp_forest, temp_forest_iter, pos_col);
	tree_encounters_count.push_back(count_of_tree_encountered(temp_forest, temp_forest_iter, pos_col, 3, 1, 0));
	reset_values(forest, temp_forest, temp_forest_iter, pos_col);
	tree_encounters_count.push_back(count_of_tree_encountered(temp_forest, temp_forest_iter, pos_col, 5, 1, 0));
	reset_values(forest, temp_forest, temp_forest_iter, pos_col);
	tree_encounters_count.push_back(count_of_tree_encountered(temp_forest, temp_forest_iter, pos_col, 7, 1, 0));
	reset_values(forest, temp_forest, temp_forest_iter, pos_col);
	tree_encounters_count.push_back(count_of_tree_encountered(temp_forest, temp_forest_iter, pos_col, 1, 2, 0));
	size_t result = multiplication_result(tree_encounters_count);
	return result;
}

long multiplication_result(const std::vector<size_t>& vec) {
	size_t result = 1;
	std::vector<size_t>::const_iterator citer = vec.begin();
	while (citer != vec.end()) {
		result *= *citer++;  // *citer++ => (*citer)++
	}
	return result;
}

void reset_values(const vec_str& forest, vec_str& temp_forest, vec_str_iter& temp_forest_iter, str_size& pos_col) {
	temp_forest.clear();
	temp_forest.insert(temp_forest.end(), forest.begin(), forest.end());
	temp_forest_iter = temp_forest.begin();
	pos_col = 0;
}