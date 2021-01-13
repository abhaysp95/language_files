// main file

#include <iostream>
#include <array>

#define SIZE 10

struct Knapsack_lists {
	std::array<int, SIZE> profits;
	std::array<size_t, SIZE> weights;
	std::array<double, SIZE> profit_weights_ratio;
};

double get_profit_knapsack(const Knapsack_lists& sack_items, size_t& capacity);
void sort_according_to_ratio(Knapsack_lists& sack_items, size_t index);
size_t get_max_index(const std::array<double, SIZE>& pw_ratio, size_t index, size_t min_index);

int main(int argc, char **argv) {
	Knapsack_lists sack_items;
	sack_items.profits = {8, 56, 53, 74, 51, 94, 72, 14, 64, 12};
	sack_items.weights = {24, 44, 27, 54, 37, 67, 39, 28, 47, 25};
	for (size_t i = 0; i < SIZE; ++i) {
		sack_items.profit_weights_ratio[i] = sack_items.profits[i] / (double)sack_items.weights[i];
	}
	std::cout << "Enter the knapsack capacity: " << std::endl;
	size_t sack_capacity;
	std::cin >> sack_capacity;
	sort_according_to_ratio(sack_items, 0);
	double profit = get_profit_knapsack(sack_items, sack_capacity);
	std::cout << "Profit is: " << profit << std::endl;
	return 0;
}

void sort_according_to_ratio(Knapsack_lists& sack_items, size_t index) {
	if (index != SIZE - 1) {
		size_t get_next_min_index = get_max_index(sack_items.profit_weights_ratio, index + 1, index + 1);
		if ((index != get_next_min_index) &&
				(sack_items.profit_weights_ratio[index] < sack_items.profit_weights_ratio[get_next_min_index])) {
			double temp_ratio = sack_items.profit_weights_ratio[index];
			sack_items.profit_weights_ratio[index] = sack_items.profit_weights_ratio[get_next_min_index];
			sack_items.profit_weights_ratio[get_next_min_index] = temp_ratio;

			int temp_profit = sack_items.profits[index];
			sack_items.profits[index] = sack_items.profits[get_next_min_index];
			sack_items.profits[get_next_min_index] = temp_profit;

			double temp_weight = sack_items.weights[index];
			sack_items.weights[index] = sack_items.weights[get_next_min_index];
			sack_items.weights[get_next_min_index] = temp_weight;
		}
		sort_according_to_ratio(sack_items, index + 1);
	}
}

size_t get_max_index(const std::array<double, SIZE>& pw_ratio, size_t index, size_t min_index) {
	if (index == SIZE) {
		return min_index;
	}
	if (pw_ratio[index] > pw_ratio[min_index]) {
		min_index = index;
	}
	return get_max_index(pw_ratio, index + 1, min_index);
}

double get_profit_knapsack(const Knapsack_lists& sack_items, size_t& capacity) {
	size_t count = 0;
	double profit = 0;
	while (capacity != 0) {
		if (capacity < sack_items.weights[count]) {
			double partition = capacity / (double)sack_items.weights[count];
			capacity = 0;
			profit += (sack_items.profits[count] * partition);
		}
		else {
			capacity -= sack_items.weights[count];
			profit += sack_items.profits[count];
		}
		count++;
	}
	return profit;
}