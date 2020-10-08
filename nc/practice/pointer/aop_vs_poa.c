#include <stdio.h>

int main(int argc, char **argv) {
	// below three lines are correct, alternative is written below these lines
	/*int (*arr)[];*/
	/*int b[5] = {1, 2, 3, 4, 5};*/
	/*arr = &b;*/


	/*int (*arr)[5] = {1, 2, 3, 4, 5};*/
	// you can't do something like this in ANSI C
	/* int (* arr)[] = &{1, 2, 3, 4, 5}; */

	// but in C99, could do something like this
	int (*arr)[] = &(int[]) {1, 2, 3, 4, 5};
	printf("pointer to an array of five numbers: \n");
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", *(*arr + i));
	}
	printf("\n");
	int b1[] = {1, 2, 3};
	int *arr1[3];
	for (int i = 0; i < 3; ++i) {
		/*arr1[i] = &b1[i];*/
		*(arr1 + i) = (b1 + i);
	}
	printf("array of pointers to five numbers: \n");
	for (int i = 0; i < 3; ++i) {
		printf("%d\t", *(*arr1 + i));
	}
	printf("\n");
	return 0;
}
