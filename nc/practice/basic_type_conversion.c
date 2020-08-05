// show basic type conversion

#include <stdio.h>

int main() {
	int i = 3.14;
	printf("i with int specifier: %d\n", i);  // 3
	printf("i with float: %f\n", i);  // 3.14
	double pi = i;
	printf("pi with double: %lf\n", pi);
	printf("pi with float: %f\n", pi);
	printf("pi with int: %d\n", pi);
	unsigned char c1 = 1;
	printf("unsigned char 1 with char: %c\n", c1);
	printf("unsigned char 1 with int: %d\n", c1);
	unsigned char c2 = -1;
	printf("unsigned char 1 with char: %c\n", c1);
	printf("unsigned char 1 with int: %d\n", c1);
	signed char c3 = -1;
	printf("signed char 1 with char: %c\n", c1);
	printf("signed char 1 with int: %d\n", c1);
	signed char c4 = 256;
	printf("signed char 1 with char: %c\n", c1);
	printf("signed char 1 with int: %d\n", c1);
	return 0;
}
