/* when we use a pointer to access data stored in a address, we call it
 * 'dereferencing' or 'indirection'.
 * eg. int *pi = &num1;  // num1 is an int variable
 * Using a pointer to access data referenced by another pointer, maybe called
 * 'multiple indirection'.
 * eg. int **ppi = &pi;  // ppi is storing adderss of pi
 * so, ppi will give address of pi
 * *ppi will give the value of pi which will be address of num1
 * and **ppi will give the value of num1
 * we, can also say that, **ppi == *pi, check it make sure
 * Note: we directly give int *ptr = array;  because array's name gives the
 * array's address too
 */

#include <stdio.h>
#define LENGTH 3

int data[LENGTH];

int main(int argc, char **argv) {
	int *pi;  // a simple pointer to an integer
	int **ppi;  // a pointer to a pointer to an integer

	for (int i = 0; i < LENGTH; ++i) {
		data[i] = i;
	}

	for (int i = 0; i < LENGTH; ++i) {
		printf("%d\n", *(data + i));
		// incrementing 1 works because that 1 is int, which already of 4 byte,
		// so you don't have to do 4*i, to get value
	}

	pi = data;  // set the pointer to an integer to the start of the data array
	ppi = &pi;  // and set the pointer to a pointer to pi itself

	for (int i = 0; i < LENGTH; ++i) {
		printf("Loop[%d] array address is %p\n", i, data);
		printf("Item pointed to by pi is %d\n", *pi);
		printf("Item pointed to by ppi is %d\n", *ppi);
		printf("Item pointed to by ppi is %p\n", *ppi);
		printf("Item pointed to by double indirection of ppi is %d\n\n", **ppi);
		printf("The value of pi is %p and it points to %d\n", pi, *pi);
		printf("The address of pi is %p and and the value of ppi(what it points to) is %p\n", &pi, ppi);
		printf("The address of ppi is %p and is not equal to value of ppi %p\n\n\n", &ppi, ppi);
		// this shows that ppi and pi are not forming any type of array, that's
		// why &pi != pi and &ppi != ppi
		pi += 1;
		// so, they just happen to be side by side but not forming an array
		/* so, pi and ppi are just one pointer variable, at first iteration, pi
		 * stores the address of data array, second iteration, pi is
		 * incremented by 1(which means address stored at pi + 4(type int)), so
		 * now pi is storing let's say 44, instead of 40, but address of pi
		 * will be same, and since address of pi will be same, so will be the
		 * value of ppi, and also &ppi. But *ppi will now point to the address
		 * 44 which is the value of pi at that time, instead of 40.
		 */
	}

	return 0;
}
