// function file, for process1.c file

#include <stdio.h>
#include "extern_variable.h"  // contains x

// extern int x;

int increment();
int decrement();

int increment() {
	x++;
	printf("Inside functions_for_extern.c: x = %d\n", x);
	return 0;
}

int decrement() {
	x--;
	printf("Inside functions_for_extern.c: x = %d\n", x);
	return 0;
}
