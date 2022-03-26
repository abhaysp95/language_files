// main file

#include <stdio.h>
#include <stdlib.h>

void factors(int num) {
	for (size_t i = 2; i <= num / 2; ++i) {
		if (num % i == 0) {
			printf("%zu\t", i);
		}
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int size;
	scanf("%d", &size);

	int *arr;
	arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		scanf("%d", (arr + i));
	}
	for (int i = 0; i < size; ++i) {
		printf("%d: ", *(arr + i));
		factors(*(arr + i));
	}
	printf("\n");
	return 0;
}