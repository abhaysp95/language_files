/* A function with no return value has the type void */
// Example: void perror(const char *);

/* You can also have void as parameter of function to tell compiler that no
   argument will be taken
   File *tmpfile(void);
*/

#include <stdio.h>

int main(int argc, char **argv) {
	char filename[] = "memo.txt";
	if (fopen(filename, "r") == NULL) {
		perror(filename);
	}
	// The cast operation (void)expression explicitly discards the value of
	// an expression(such as return value)
	int res = printf("Result\n");
	printf("Return value of previous printf: %d\n", res);
	(void)printf("I don't need it's return value\n");

	/* A pointer of type void * reprsents the address of an object but not type, can be used mainly to declare functions that can operate on various types of pointer arguments, or that can return a "multipurpose" pointer.
	   void *malloc(size_t size);
	   void *realloc(void *ptr, size_t size);
	   void free(void *ptr);
   */
	return 0;
}
