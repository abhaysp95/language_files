// demonstrating some basics of array in C++

#include <iostream>

using std::cout;
using std::endl;

int main() {
	// first way -> defining and initializing
	int array_of_even_nums [6] {0, 2, 4, 6, 8, 10};

	// second way -> defining and initializing but with few given values
	int scores_are [5] {3, 5};  // first two are 3 & 5, rest are 0

	// third way -> initializing all with 0
	const int gross_salary {200};
	double all_gross_salary [gross_salary] {0};

	// fourth way -> size automatically calculated(based on given array)
	int size_is [] {1, 2, 3, 4};  // size automatically calculated

	cout << "Size of \"size is\" array is: " << sizeof(size_is) << endl;
	cout << "Notice the array name: " << size_is << endl;
	// Name of array is the location of the array in memory

	cout << "Notice the array name: " << size_is[-1] << endl;
	// as array bound isn't checked this could return any value, unlike other lang

	cout << "Third even num is: " << array_of_even_nums[2] << endl;
	// in the same way you can change the value of the array elements

	return 0;
}
