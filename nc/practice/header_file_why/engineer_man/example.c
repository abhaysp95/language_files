// trying to learn use of header file

#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv) {
	// use function
	printf("%d\n", add(2, 4));

	// use macro
	printf("%d\n", ADD(3, 7));

	// use typedef
	person raytracer;
	raytracer.age = 20;
	printf("raytracer's age: %d\n", raytracer.age);
	return 0;
}
