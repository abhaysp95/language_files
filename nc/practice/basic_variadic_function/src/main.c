// main file

#include <stdio.h>
#include <stdarg.h>

int sum_all(const unsigned n, ...) {
	int i, sum = 0;
	va_list args;  // initialize argument pointer
	va_start(args, n);  // list is initiated and points to first element
	for (i = 0; i < n; ++i) {
		sum += va_arg(args, int); // everytime it is called it points to next arg
	}
	va_end(args);
	return sum;
}

int main(int argc, char **argv) {
	int sum = sum_all(5, 293, 293, 901, 023, 024);
	printf("sum is: %d\n", sum);
    return 0;
}