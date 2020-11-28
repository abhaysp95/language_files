// main file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1() {
	const int NUM_HEIGHTS = 3;
	int *heights = malloc(NUM_HEIGHTS * sizeof(*heights));  // sizeof(int)
	/* in above line sizof(*heights) doesn't mean that I'm dereferencing it,
	 * it simply means to whatever datatype it is pointing to or going to
	 * be, so it's int in this case */
	for (int i = 0; i < NUM_HEIGHTS; ++i) {
		heights[i] = i * i;
		printf("%d: %d\n", i, heights[i]);
	}
	free(heights);
}

void test2() {
	const int NUM_WEIGHTS = 5;
	long long *weights = malloc(NUM_WEIGHTS * sizeof(weights));
	for (int i = 0; i < NUM_WEIGHTS; ++i) {
		weights[i] = 100 + i;
		printf("%ld: %lld\n", i, weights[i]);
	}
	weights[0] = 0;
	free(weights);
}

void test3() {
	const int NUM_HEIGHTS = 10;
	int* heights = malloc(NUM_HEIGHTS * sizeof(*heights));
	/*for (int i = 0; i < NUM_HEIGHTS; ++i) {
		if ((heights = NULL)) {
			heights = malloc(NUM_HEIGHTS * sizeof(*heights));
		}
	}*/
	free(heights);
}

char* getString() {
	char message[100] = "Hello World";
	char* ret = message;
	return ret;
}

void test4() {
	printf("String: %s\n", getString());
}

int main(int argc, char **argv) {
	/*test1();*/
	/*test2();*/
	/*test3();*/
	test4();
    return 0;
}