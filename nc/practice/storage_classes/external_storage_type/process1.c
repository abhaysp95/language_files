// Demonstration of extern keyword

// If a variable is defined(maybe not declared) outside of the function, not
// only it's available to all the functions in the file but also available to
// functions defined in other files. In the other files the variable should be
// declared as extern

#include <stdio.h>
#include "functions_for_extern.c"  // including a .c file is a bad practice
// but for this example we'll use .c file

// this all done when included functions_for_extern.c file
int x = 35;  // defined
int increment();
int decrement();

/*main function*/
int main(int argc, char* argv[]) {
	printf("Inside process1.c: x = %d\n", x);
	increment();
	decrement();
	return 0;
}

/*#include "functions_for_extern.h"*/
// main function
/*int main(int argc, char* argv[]) {*/
	/*printf("Inside process1.c: x = %d\n", x);*/
	/*increment();*/
	/*printf("After increment: x = %d\n", x);*/
	/*decrement();*/
	/*printf("After decrement: x = %d\n", x);*/
	/*return 0;*/
/*}*/
