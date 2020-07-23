// another demonstration of external storage type

#include <stdio.h>

int x = 35;  // defining

// main function
int main(int argc, char* argv[]) {
	extern int y;  // declaring
	printf("%d %d\n", x, y);
	return 0;
}

int y = 31;  // defining


// a variable should have been defined before it's usage
// x is defined already before use in printf, so no need to declare x
// whereas, y wasn't defined, so we had to atleast declare y
// No space is reseved when we declare a variable, but
// when we define a variable, space is reserved to the memory
