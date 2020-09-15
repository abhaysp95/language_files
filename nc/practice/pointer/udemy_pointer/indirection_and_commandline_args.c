// showing how to access commandline arguments

#include <stdio.h>

int main(int argc, char **argv) {  // pointer to pointer to char
	// showing arguments with the help of array
	printf("\n--------------------------------\n");
	for (int i = 0; i < argc; ++i) {
		printf("arg %d is %s\n", i, argv[i]);
	}

	printf("\n--------------------------------\n");

	// showing arguments with the help of pointer
	for (int i = 0; i < argc; ++i) {
		// argv += i;  // now this will show, 0, then 1, then 3, then 6
		printf("arg %d is %s\n", i, *argv);
		argv += 1;
	}
	printf("--------------------------------\n");
	return 0;
}
