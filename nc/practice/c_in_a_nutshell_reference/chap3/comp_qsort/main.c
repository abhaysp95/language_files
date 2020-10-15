// A comparision function for qsort()

#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 20

/* void qsort(void *arry, size_t n, size_t element_size,
   int (*compare)(const void *, const void *)); */

/* A function to compare any two floats elements, for use as a call-back
 * function by qsort(). Arguments are passed by pointer.
 * Returns:
 *   -1, if the first is less than second
 *   0 if the elements are equal
 *   1 if the first is greater than
 * the second
 */

int floatcmp(const void *p1, const void *p2) {
	float x = *(float *)p1,
		  y = *(float *)p2;
	return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

void print(const void *arr) {
	float *array = (float *)arr;
	printf("Size of got arr: %lu\n", sizeof(array));  // 8, points to first block

	for (int i = 0; i < ARR_LEN; ++i) {
		printf("%.2f\t", *(array + i));
	}
	printf("\n");
}

/*
 * The main function sorts an array of float
 */

int main(int argc, char **argv) {
	/* Allocate space for the array dynamically */
	float *pNumbers = malloc(ARR_LEN * sizeof(float));

	for(int i = ARR_LEN, j = 0; i > 0; --i, ++j) {
		*(pNumbers + j) = (float){i};
	}

	printf("print before sorting\n");
	print(pNumbers);

	/* ... Handle errors, initialize array elements ... */
	/* sort the array */
	qsort(pNumbers, ARR_LEN, sizeof(float), floatcmp);

	/* ... print after sorting ... */
	printf("print after sorting\n");
	print(pNumbers);

	return 0;
}

/* the malloc() funciton returns a pointer to void. Before you can access the
 * memory block, the void pointer must always be converted into a pointer to an
 * object */

/* In the above example, malloc returns a void *, which is implicitly converted
 * to float * in the assignment to pNumbers. In the call to qsort(), the first
 * argument pNumbers is implicitly converted from float * to void *, and the
 * function floatcmp is implicitly interpreted as function pointer. Finally,
 * when the floatcmp() function is called by qsort(), it recieves arguments of
 * the type void *, the 'universal' pointer type, and must convert them
 * explicitly to float * before dereferencing them to initialize its float
 * variables. */


/* so, regarding, floatcmp is implicitly interpreted as function pointer, is this same as:
   void (*compare)(const void *, const void *) = floatcmp;
   floatcmp(....);  // calling with appropirate parameters
*/
