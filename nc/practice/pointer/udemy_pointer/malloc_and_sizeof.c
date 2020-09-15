// using sizeof with malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *s;
	int stringsize = sizeof("Hello");
	printf("Size of string s is %d\n", stringsize);

	s = (char *)malloc(stringsize);  // when allocation failed malloc/calloc returns null pointer
	// pointers with 0 are considered as null pointers
	if (s == NULL) {
		printf("Failed!");
		exit(1);
	}

	// copy the string into the newly allocated memory
	strncpy(s, "Hello", stringsize);
	printf("s is now: %c\n", *s);
	*s = 'C';
	printf("s is now: %c\n", *s);
	return 0;
}
