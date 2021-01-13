// main file

/***********************************************************************/
/** find the max and min with one call using divide & conquer approach */
/***********************************************************************/

#include <iostream>
#include <array>

#define ARRAY_SIZE 10
#define MM 2

struct Result {
	int max{};
	int min{};
};

std::array<int, MM> find_max_min(const std::array<int, ARRAY_SIZE>& array, size_t start,
		size_t end, int& max, int& min);
void find_max_min(const std::array<int, ARRAY_SIZE>& array,
		std::array<int, MM>& resultant, size_t start, size_t end,
		int& max, int& min);
void find_max_min(const std::array<int, ARRAY_SIZE>& array,
		Result& result, size_t start, size_t end,
		int& max, int& min);

int main(int argc, char **argv) {
	std::array<int, ARRAY_SIZE> numbers{0};
	std::cout << "Enter the numbers: " << std::endl;
	for (size_t i = 0; i < ARRAY_SIZE; ++i) {
		std::cin >> numbers[i];
	}
	//std::array<int, ARRAY_SIZE> numbers = {2, 6, 8, 10, 9, 6, 5, 4, 3, 1};
	Result result;
	int max{}, min{};
	//std::array<int, MM> resultant = find_max_min(numbers, 0, ARRAY_SIZE - 1, max, min);
	//std::array<int, MM> resultant;
	//find_max_min(numbers, resultant, 0, ARRAY_SIZE - 1, max, min);
	find_max_min(numbers, result, 0, ARRAY_SIZE - 1, max, min);
	std::cout << "Max: " << result.max << ", Min: " << result.min << std::endl;
return 0;
}


/** first approach */

std::array<int, MM> find_max_min(const std::array<int, ARRAY_SIZE>& array, size_t start,
		size_t end, int& max, int& min) {
	std::array<int, MM> return_arr;  // array that'll contain only max & min
	if (start == end) {  // if only one element left in array
		max = min = array[start];
		return_arr = {max, min};
	}  // first base condition
	else if (start == end - 1) {  // if there are only two elements in array
		max = array[start] < array[end] ? array[end] : array[start];
		min = array[start] > array[end] ? array[end] : array[start];
		return_arr = {max, min};
	}  // second base condition
	else {
		size_t mid = (end + start) / 2;  // find mid
		// first recursive call will be from start(0) to mid value
		std::array<int, MM> compare_set1 = find_max_min(array, start, mid, max, min);
		// second recursive call will be from mid + 1 to end
		std::array<int, MM> compare_set2 = find_max_min(array, mid + 1, end, max, min);
		// in both compare set, first index is going to be maximum and second is minimum
		// find max and min after both recursive calls are done for one time
		max = compare_set1[0] > compare_set2[0] ? compare_set1[0] : compare_set2[0];
		min = compare_set1[1] < compare_set2[1] ? compare_set1[1] : compare_set2[1];
		return_arr = {max, min};
	}
	return return_arr;
}


/** second approach */

void find_max_min(const std::array<int, ARRAY_SIZE>& array,
		std::array<int, MM>& resultant, size_t start, size_t end, int& max, int& min) {
	if (start == end) {  // if there's only one element in the array left
		max = min = array[start];
		resultant[0] = max;
		resultant[1] = min;
	}  // first base condition
	else if (start == end - 1) {  // if there are only two elements left
		max = array[start] < array[end] ? array[end] : array[start];
		min = array[start] > array[end] ? array[end] : array[start];
		resultant[0] = max;
		resultant[1] = min;
	}  // second base condition
	else {
		size_t mid = (end + start) / 2;
		// first recursive call will be from start(0) to mid value
		std::array<int, MM> compare_set1 = find_max_min(array, start, mid, max, min);
		// second recursive call will be from mid + 1 to end
		std::array<int, MM> compare_set2 = find_max_min(array, mid + 1, end, max, min);
		// in both compare set, first index is going to be maximum and second is minimum
		// find max and min after both recursive calls are done for one time
		max = compare_set1[0] > compare_set2[0] ? compare_set1[0] : compare_set2[0];
		min = compare_set1[1] < compare_set2[1] ? compare_set1[1] : compare_set2[1];
		resultant[0] = max;
		resultant[1] = min;
	}
}


/** third approach */

void find_max_min(const std::array<int, ARRAY_SIZE>& array,
		Result& result, size_t start, size_t end, int& max, int& min) {
	if (start == end) {  // if there's only one element in the array left
		max = min = array[start];
		result.max = max;
		result.min = min;
	}  // first base condition
	else if (start == end - 1) {  // if there are only two elements left
		max = array[start] < array[end] ? array[end] : array[start];
		min = array[start] > array[end] ? array[end] : array[start];
		result.max = max;
		result.min = min;
	}  // second base condition
	else {
		size_t mid = (end + start) / 2;
		// first recursive call will be from start(0) to mid value
		std::array<int, MM> compare_set1 = find_max_min(array, start, mid, max, min);
		// second recursive call will be from mid + 1 to end
		std::array<int, MM> compare_set2 = find_max_min(array, mid + 1, end, max, min);
		// in both compare set, first index is going to be maximum and second is minimum
		// find max and min after both recursive calls are done for one time
		max = compare_set1[0] > compare_set2[0] ? compare_set1[0] : compare_set2[0];
		min = compare_set1[1] < compare_set2[1] ? compare_set1[1] : compare_set2[1];
		result.max = max;
		result.min = min;
	}
}