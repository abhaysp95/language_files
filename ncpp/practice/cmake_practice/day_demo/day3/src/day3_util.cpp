// cpp file for "day3_util.hpp"

#include "../inc/day3_util.hpp"

size_t count_of_tree_encountered(const vec_str& forest, vec_str_iter& forest_iter,
		str_size& pos_col, str_size go_right, str_size go_down, size_t trees_met) {
	if (forest_iter >= forest.end()) {
		return trees_met;
	}
	if (forest_iter != forest.begin()) {
		if (pos_col + go_right >= forest_iter->size()) {
			/** duplicate the column if there's no next position in the column to move to */
			duplicate_column(forest_iter, pos_col, go_right);
		}
		if (forest_iter->at(pos_col) == '#') {
			forest_iter->at(pos_col) = 'X';
			trees_met++;
		}
		else {
			forest_iter->at(pos_col) = 'O';
		}
	}
	//std::cout << *forest_iter << "\n";
	forest_iter += go_down;
	pos_col += go_right;
	return count_of_tree_encountered(forest, forest_iter, pos_col, go_right, go_down, trees_met);
}

void duplicate_column(vec_str_iter& forest_iter, const str_size& pos_col, const str_size& go_right) {
	while (forest_iter->size() <= pos_col + go_right) {
		forest_iter->insert(forest_iter->end(), forest_iter->begin(), forest_iter->end());
	}
}