// pointer that points to 0th element of array and pointer that points to the whole array are different


#include <stdio.h>

int main(int argc, char **argv) {
	int *p;  // pointer to an int
	int (*parr)[5];  // pointer to an array of integer 5
	int my_array[5];  // array of integer 5

	p = my_array;
	parr = &my_array;

	printf("Address of p: %p\n", p);
	printf("Address of parr: %p\n", parr);

	p++;
	parr++;

	printf("After incrementing\n");  // incremented 4 byte
	printf("Address of p: %p\n", p);  // incremented 5 * 4 byte
	printf("Address of parr: %p\n", parr);

	printf("Dereferencing parr one level: %d\n", *parr);
	printf("Dereferencing parr one level: %p\n", *parr);  // same to parr

	printf("Dereferencing parr one level: %p\n", *parr + 1);  // base type is a pointer to int
	printf("Dereferencing parr one level: %p\n", *(parr + 1));  // base type pointer to an array
	return 0;
}


/* So, on dereferencing parr, you will get *parr. The important thing to
 * notice is although parr and *parr points to the same address, but parr's
 * base type is a pointer to an array of 5 integers, while *parr base type is
 * a pointer to int. This is an important concept and will be used to access
 * the elements of a 2-D array.
 */
