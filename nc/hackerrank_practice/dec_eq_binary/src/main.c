// main file

#include <stdio.h>
#include <stdlib.h>

int dec_to_bin(int num, int* arr, unsigned int arr_size) {
	static unsigned int count = 0;
	if (num <= 0) {
		return count;
	}
	if (count == arr_size) {
		arr_size *= 2;
		arr = realloc(arr, arr_size * sizeof(int));
		if (arr == NULL) {
			perror("Can't reallocate array\n");
		}
	}
	*(arr + count++) = num % 2;
	return dec_to_bin(num / 2, arr, arr_size);
}

int main(int argc, char **argv) {
	int num = 0;
	scanf("%d", &num);
	unsigned int arr_size = 8;
	int* arr = (int*)malloc(arr_size * sizeof(int));
	if (arr == NULL) {
		perror("Can't create array\n");
	}
	/* unsigned int count = 0;
	while (num > 0) {
		if (count == arr_size) {
			arr_size *= 2;
			arr = realloc(arr, arr_size * sizeof(int));
			if (arr == NULL) {
				perror("Can't reallocate array\n");
			}
		}
		*(arr + count++) = num % 2;
		num /= 2;
	} */
	unsigned int count = dec_to_bin(num, arr, arr_size);
	for (int i = count - 1; i >= 0; --i) {
		printf("%d", *(arr + i));
	}
	printf("\n");
	free(arr);
	return 0;
}