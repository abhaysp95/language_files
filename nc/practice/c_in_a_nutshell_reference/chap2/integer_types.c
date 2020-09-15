#include <stdio.h>
#include <stddef.h>
#include <uchar.h>
#include <stdint.h>
#define ARR_SIZE 100

int main(int argc, char **argv) {
	size_t a = 10;
	char32_t c = 'a';
	printf("%zd\t", a);
	printf("%c\n", c);

	// int_fast<SIZE>_t means, fastest type accessible with least having given size
	int_fast32_t arr[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; ++i) {
		*(arr + i) = (int_fast32_t)i;
	}
	// print
	// int_fast32_t comparable to long
	for (int i = 0; i < ARR_SIZE; ++i) {
		printf("%ld\t", *(arr + i));
	}
	return 0;
}
