#include <stdio.h>
#define ROWS 2
#define COLUMNS 3
#define CELLS ( ROWS * COLUMNS )

int main(int argc, char **argv) {
	int first_arr[ROWS][COLUMNS] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	// assigning 2d array to a pointer variable
	int (*ptr2row)[COLUMNS] = first_arr;  // now this is same as accessing first_arr, or *(first_arr), since ptr2row is also the pointer to array of integers 3

	int (*ptr2element) = &first_arr[0][0];
	int (*ptr2array)[ROWS][COLUMNS] = &first_arr;

	printf("ptr2array have the address of: %p\n", ptr2array);
	printf("ptr2array with value at base: %d\n", *(*(ptr2array)));
	printf("ptr2array with one level of dereferencing: %p\n", *ptr2array);
	printf("ptr2array with one level of dereferencing: %p\n", *ptr2array + 1);
	printf("ptr2array with one level of dereferencing having value: %d\n", *(*(ptr2array) + 1));
	printf("ptr2array with two level of dereferencing: %p\n", **ptr2array);
	printf("ptr2array with two level of dereferencing: %p\n", **ptr2array + 1);
	printf("ptr2array with two level of dereferencing having value: %d\n", **(*(ptr2array) + 1));

	// In C, 2d arrays are stored in row-major order
	// base_type of first_arr is pointer to an array of 3 integers
	// so, its like first_arr having 2 array, where every array has 3 elements
	// also, name of the array is constant pointer to 0th element of that array

	printf("First_arr(inside main) is: \n");
	printf("First array from 2d-array: %p\n", first_arr);  // base type pointer to an array
	printf("First array from 2d-array: %p\n", first_arr + 1);
	// gap from above is of 12 bytes

	printf("First array from 2d-array: %p\n", *first_arr);  // base type pointer to an int
	printf("First array from 2d-array: %p\n", *(first_arr + 1));
	printf("First array from 2d-array: %p\n", *first_arr + 1);


	printf("First array from 2d-array: %d\n", **first_arr);
	printf("First array from 2d-array: %d\n", **(first_arr + 1));
	printf("First array from 2d-array: %d\n", **first_arr + 1);

	printf("\n-----------------------\n\n");

	printf("ptr2row(inside main) is: \n");
	printf("ptr2row from 2d-array: %p\n", ptr2row);  // base type pointer to an array
	printf("ptr2row from 2d-array: %p\n", ptr2row + 1);
	// gap from above is of 12 bytes

	printf("ptr2row from 2d-array: %p\n", *ptr2row);  // base type pointer to an int
	printf("ptr2row from 2d-array: %p\n", *(ptr2row + 1));
	printf("ptr2row from 2d-array: %p\n", *ptr2row + 1);


	printf("ptr2row from 2d-array: %d\n", **ptr2row);
	printf("ptr2row from 2d-array: %d\n", **(ptr2row + 1));
	printf("ptr2row from 2d-array: %d\n", **ptr2row + 1);

	printf("\n-----------------------\n\n");

	printf("ptr2element(inside main) is: \n");
	printf("ptr2array with one level of dereferencing: %p\n", *ptr2array);
	printf("ptr2array with one level of dereferencing: %p\n", *ptr2array + 1);
	printf("ptr2array with one level of dereferencing having value: %d\n", *(*(ptr2array) + 1));
	printf("ptr2element from 2d-array: %p\n", ptr2element);  // base type pointer to an array
	printf("ptr2element from 2d-array: %p\n", ptr2element + 1);
	// gap from above is of 12 bytes

	printf("ptr2element from 2d-array: %p\n", *ptr2element);  // base type pointer to an int
	printf("ptr2element from 2d-array: %p\n", *(ptr2element + 1));
	printf("ptr2element from 2d-array: %p\n", *ptr2element + 1);


	printf("ptr2element from 2d-array: %d\n", *ptr2element);
	printf("ptr2element from 2d-array: %d\n", *(ptr2element + 1));
	printf("ptr2element from 2d-array: %d\n", *ptr2element + 1);

	printf("\n-----------------------\n\n");

	printf("Elements of array: \n");
	for (int i = 0; i < ROWS; ++i) {
		// for (int j = 4; j < COLUMNS + 4; ++j) {
		for (int j = 0; j < COLUMNS; ++j) {
			printf("%d\t", **(first_arr + i) + j);  // this is just literally adding j, to the dereferenced(upto top) first_arr elements
		}
		printf("\n");
	}

	printf("\n-----------------------\n\n");

	printf("Elements of array: \n");
	for (int i = 0; i < ROWS; ++i) {
		// for (int j = 4; j < COLUMNS + 4; ++j) {
		for (int j = 0; j < COLUMNS; ++j) {
			printf("%d\t", *(*(first_arr + i) + j));  // this is adding j to dereferenced first_arr(which would now be pointer to an int), so adding 4 more will make it shift 4*4 byte more
		}
		printf("\n");
	}
	// the above same method would have been used to print elements with ptr2row
	return 0;
}
