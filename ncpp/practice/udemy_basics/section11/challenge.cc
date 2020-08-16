#include <iostream>
#include <vector>
#include <iomanip>

void print_menu();
void print_list(std::vector<int>);
void add_number_to_list(std::vector<int> &);
void show_the_mean(std::vector<int>);
int find(std::vector<int>, int);  // added at last moment
void find_the_num(std::vector<int>);
void find_the_smallest(std::vector<int>);
void find_the_largest(std::vector<int>);
void clear_the_list(std::vector<int> &);

void print_menu() {
	std::cout << "\n[P/p] - Print numbers" << std::endl;
	std::cout << "[A/a] - Add a number" << std::endl;
	std::cout << "[M/m] - Display mean of the number" << std::endl;
	std::cout << "[F/f] - Find the element in the list" << std::endl;
	std::cout << "[S/s] - Display the smallest number" << std::endl;
	std::cout << "[L/l] - Display the largest number" << std::endl;
	std::cout << "[C/c] - Clear the list" << std::endl;
	std::cout << "[Q/q] - Quit\n" << std::endl;
}

void print_list(std::vector<int> numbers) {
	std::cout << "[ ";
	for (int num: numbers) {
		std::cout << num;
		if (num != numbers.back()) {
			std::cout << " ";
		}
	}
	std::cout << " ]" << std::endl;
}

void add_number_to_list(std::vector<int> &numbers) {
	int num {};
	bool flag = true;
	std::cout << "Enter the number to add in list: ";
	std::cin >> num;
	for (int number: numbers) {
		if (number == num) {
			flag = false;
			break;
		}
	}
	if (flag) {
		numbers.push_back(num);
	}
	else {
		std::cout << "Duplicate Number, can't make it to the number list" << std::endl;
	}
}

void show_the_mean(std::vector<int> numbers) {
	int sum {};
	double mean {};
	for (int num: numbers) {
		sum += num;
	}
	mean = static_cast<double>(sum) / numbers.size();
	std::cout << std::fixed << std::setprecision(3) << std::endl;
	std::cout << "Mean of the numbers in the list is: " << mean << std::endl;
}

int find(std::vector<int> numbers, int key) {
	int count {};
	for (int num: numbers) {
		if (key == num) {
			return count;
		}
		count++;
	}
	return -1;
}

void find_the_num(std::vector<int> numbers) {
	int key {}, count {};
	std::cout << "Enter the element to find: " << std::endl;
	std::cin >> key;
	int if_found = find(numbers, key);
	if (if_found) {
		std::cout << "Target was found at " << if_found << std::endl;
	}
}

void find_the_smallest(std::vector<int> numbers) {
	int key {numbers.at(0)};
	for (int num: numbers) {
		if (key > num) {
			key = num;
		}
	}
	std::cout << "Smallest element in the list is: " << key << std::endl;
}

void find_the_largest(std::vector<int> numbers) {
	int key {numbers.at(0)};
	for (int num: numbers) {
		if (key < num) {
			key = num;
		}
	}
	std::cout << "Largest element in the list is: " << key << std::endl;
}

void clear_the_list(std::vector<int> &numbers) {
	numbers.clear();
	std::cout << "List all clear" << std::endl;
}

int main() {
	std::vector<int> num_list {};
	char choice {};
	do {
		print_menu();
		std::cout << "Enter the choice: " << std::endl;
		std::cin >> choice;
		if (choice >= 65 && choice <= 90) {
			choice = choice + 32;
		}
		switch (choice) {
			case 'p':
				print_list(num_list);
				break;
			case 'a':
				add_number_to_list(num_list);
				break;
			case 'm':
				show_the_mean(num_list);
				break;
			case 'f':
				find_the_num(num_list);
				break;
			case 's':
				find_the_smallest(num_list);
				break;
			case 'l':
				find_the_largest(num_list);
				break;
			case 'c':
				clear_the_list(num_list);
				break;
			default:
				std::cout << "You entered the wrong choice" << std::endl;
		}
	} while( choice != 'q' && choice != 'Q' );
	return 0;
}
