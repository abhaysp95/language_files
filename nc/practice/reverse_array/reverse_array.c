// testing reverse_array.H

#include <stdio.h>
#include "reverse_array.h"

int main(int argc, char **argv) {
	int array[] = {1, 2, 3, 4, 5};
	printf("\nBefore: \n");
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", *(array + i));
	}
	reverse_array(array, 5);
	printf("\nAfter: \n");
	for (int i = 0; i < 5; ++i) {
		printf("%d\t", *(array + i));
	}
	return 0;
}
