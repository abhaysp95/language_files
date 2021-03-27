// main file

/** for a given circular array(means you can wrap start and end), you have to
  find max sum of subarray

  There can be 2 cases, either max_sum is obtained by non-wrapping the array
  (just a simple array) or with wrapping a array

  we'll use kadane's algo to obtain sum of non-wrapping array, and we'll
  also try to obtain the sum by wrapping the array and the maximum between those
  two will be the max sum
*/

#include <iostream>
#include <cassert>

int kadane_sum(const int* arr, const size_t& arr_size);

int main(int argc, char **argv) {
	size_t arr_size{};
	std::cin >> arr_size;
	assert(0 < arr_size);
	int* arr = new int[arr_size];
	for (size_t idx = 0; idx < arr_size; ++idx) {
		std::cin >> *(arr + idx);
	}

	int non_wrap_sum = kadane_sum(arr, arr_size);

	/** now to obtain sum with wrapping, get the non-contributing element,
	  by reversing sign of all the elements and applying kadane's algo, the
	  max sum will be returned and that one sum will be the sum of
	  non-contributing elements and add that with the total sum of original
	  array and you'll get the result
	*/

	int wrap_sum{};
	int total_sum{};
	for (size_t idx = 0; idx < arr_size; ++idx) {
		total_sum += *(arr + idx);
		*(arr + idx) = -*(arr + idx);
	}
	wrap_sum = total_sum + kadane_sum(arr, arr_size);

	std::cout << "Max subarray sum of circular array: " <<
		std::max(non_wrap_sum, wrap_sum) << std::endl;
	return 0;
}

int kadane_sum(const int* arr, const size_t& arr_size) {
	int max_sum{};  // 0 is alright, cause you're going to get min as 0 here only
	int current_sum{};
	for (size_t idx = 0; idx < arr_size; ++idx) {
		current_sum += *(arr + idx);
		if (current_sum < 0) {
			current_sum = 0;
		}
		max_sum = std::max(max_sum, current_sum);
	}
	return max_sum;
}