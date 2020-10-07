#include <stdio.h>

int main(int argc, char **argv) {
	int (*arr)[];
	int b[5] = {1, 2, 3, 4, 5};
	arr = &b;
	/*int (*arr)[5] = {1, 2, 3, 4, 5};*/
	printf("pointer to an array of five numbers: \n");
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", *(*arr + i));
	}
	printf("\n");
	/*int b1[] = {1, 2, 3};*/
	int *arr1[3] = {5, 6, 7};
	for (int i = 0; i < 3; ++i) {
		/*arr1[i] = &b1[i];*/
		*(arr1 + i) = (b1 + 1);
	}
	printf("array of pointers to five numbers: \n");
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", *(*arr + i));
	}
	printf("\n");
	return 0;
}
