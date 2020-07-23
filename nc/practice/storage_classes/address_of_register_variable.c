// check if address of register variable is accessible or not


#include <stdio.h>

// main function
int main(int argc, char* argv[]) {
	register int x = 5;  // declaration and defining
	int *address;  // declaration
	address = &x;  // error=> address of register variable x requested
	printf("%p %d\n", address, *address);
	return 0;
}
