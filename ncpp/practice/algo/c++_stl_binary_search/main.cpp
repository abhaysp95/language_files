#include <iostream>
#include <algorithm>
#include <cstdbool>
#include <vector>

void using_binary_search() {
	int arr[] = {1, 4, 5, 8, 9};
	std::cout << std::binary_search(arr, arr + 5, 3) << '\n';
	std::cout << std::binary_search(arr, arr + 5, 4) << '\n';
	/** can also use iterators */
}

void using_lower_bound() {
	int arr[] = {1, 4, 5, 6, 9, 9};
	std::cout << std::lower_bound(arr, arr + 6, 4) << '\n';  // returns iterator
	std::cout << std::lower_bound(arr, arr + 6, 7) << '\n';
	std::cout << std::lower_bound(arr, arr + 6, 10) << '\n';
	std::cout << std::lower_bound(arr, arr + 6, 4) - arr << '\n';  // print index
	std::cout << std::lower_bound(arr, arr + 6, 7) - arr << '\n';
	std::cout << std::lower_bound(arr, arr + 6, 10) - arr << '\n';
	/** lower_bound returns first occurence of the element if it occurs and if
	 * doesn't occur then return iterator pointing to element which is
	 * immediate next greator of the element */
}

void using_upper_bound() {
	std::vector<int> arr {1, 4, 5, 6, 9, 9};
	std::cout << *std::upper_bound(arr.begin(), arr.end(), 4) << '\n';  // returns iterator
	std::cout << *std::upper_bound(arr.begin(), arr.end(), 7) << '\n';

	// what type of iterator is returned by upper_bound/lower_bound and how do
	// you work with them ?
	/* if (std::upper_bound(arr.begin(), arr.end(), 10) > arr.end())
		std::cout << "upper_bound for 10 not found\n"; */
}

/** find first occurence of 'x' in sorted array, if not exist print -1 */
void sol1(int *arr, int N, int k) {
	size_t pos = std::lower_bound(arr, arr + N, k) - arr;
	if (pos < N) {
		if (arr[pos] == k)
			std::cout << "found, " << pos << '\n';
		else
			std::cout << "not found, -1\n";
	}
	else
		std::cout << "not found, -1\n";
}

/** find last occurence of 'x' in sorted array, if not exist, print -1 */
void sol2(int *arr, int N, int k) {
	int pos = std::upper_bound(arr, arr + N, k) - arr;
	--pos;
	if (pos >= 0 && arr[pos] == k)
		std::cout << "found, " << pos << '\n';
	else
		std::cout << "not found\n";
}

/** find the largest number which is smaller than 'X'
 *
 * search for lower_bound(a, a + N, X) and decrement one time
 * consider the edge case when the return pos by lower bound is index 0 */

/** find the smallest number greater than 'X'
 *
 * search for upper_bound(a, a + N, X)
 * consider the edge case where the pos returned is size of a upper_bound
 * points to last element of arr */

int main(int argc, char **argv) {
	using_binary_search();
	using_lower_bound();
	using_upper_bound();

	int arr[] = {1, 4, 4, 4, 4, 9, 9, 10, 11};
	sol1(arr, 9, 12); // k being, 4, 2, 12
	sol2(arr, 9, 0);  // k being 4, 2, 0
}
