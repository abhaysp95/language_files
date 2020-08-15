// pass the array

#include <iostream>
#include <typeinfo>

void print_array(const int, size_t);
void update_array(int, size_t, int);

void print_array(const int array [], size_t size) {
	for (int i{}; i < size; ++i) {
		std::cout << array[i];
		if (i < size -1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void update_array(int array [], size_t size, int update_num) {
	for (int i{}; i < size; ++i) {
		array[i] = update_num;
	}
}

int main() {
	int array[5] {1, 2, 3, 4, 5};

	print_array(array, 5);
	update_array(array, 5, 100);
	print_array(array, 5);

	return 0;
}
