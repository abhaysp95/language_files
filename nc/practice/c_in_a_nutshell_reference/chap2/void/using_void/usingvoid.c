// Demonstrates uses of the type void

#include <stdio.h>
#include <stdlib.h>  // for following function prototypes
	// void srand(unsigned int seed);
	// int rand(void);
	// void *malloc(size_t size);
	// void free(void *ptr);
	// void exit(int status);
#include <time.h>

enum {
	ARR_LEN = 100
};

int main(int argc, char **argv) {
	int i,  // obtain some storage space
		*pNumbers = malloc(ARR_LEN * sizeof(int));
	/*pNumbers = NULL;*/
	if (pNumbers == NULL) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}
	srand((unsigned)time(NULL));  // Initialize the random number generator
	for (i = 0; i < ARR_LEN; ++i) {
		/*pNumbers[i] = rand(100) % 1000; */
		pNumbers[i] = rand() % 1000;  // store some random number
	}
	printf("\n%d random numbers between 0 and 999\n", ARR_LEN);
	for (i = 0; i < ARR_LEN; ++i) {
          /* print one number per loop iterate and a newline after every 10
           * numbers, release the storage space */
          printf("%6d", pNumbers[i]);
          if (i % 10 == 9) {
            putchar('\n');
		}
	}
	/*printf("A simple random number: %d", rand());
		it's a really big number */
	free(pNumbers);
	return 0;
}
