// C file for my_func

#include <stdio.h>
#define __myfile_h
/* this defined so, give_fibonacci from "my_func.h" will not be included,
see 'my_func.h' */
#include "my_func.h"
#include "my_func1.h"

// main function
int main(int argc, char* argv[]) {
	int num = 0, result = 0;
	printf("For fibonacci with recursion: \n");
	printf("Enter the number: ");
	scanf("%d", &num);
	result = give_fibonacci(num);
	printf("Result is: %d\n", result);

	printf("For factorial with recursion: \n");
	printf("Using same number as above: \n");
	result = give_factorial(num);
	printf("Result is: %d\n", result);
	return 0;
}
