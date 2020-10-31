/* The type qualifiers in C are const, volatile and restrict. The compiler
 * implicitly converts any pointer to int into a pointer to const int where
 * necessary for example. If you want to remove qualification rather than adding
 * one, however, you must use an explicit type conversion */

#include <stdio.h>

int main(int argc, char **argv) {
	int n = 77;
	const int *ciPtr = 0;  // a pointer to const int,
	// the pointer itself is not constant

	ciPtr = &n;         // Implicitly converts the address to the type const int *
	n = *ciPtr + 3;     // OK: this has the same effect as n = n + 3;
	/**ciPtr *= 2;        // Error: you can't change an object referenced by a pointer to const int*/
	*(int *)ciPtr *= 2; // OK: explicitly converts the pointer into pointer to a nonconstant int
	/**ciPtr *= (const int)2;  // OK: explicitly converts 2 into the const int, the type which ciPtr accepts*/
	// but will not work, since ciPtr is of type const int, which can't be changed
	const int *newPtr =  &(int){3};  // since, C99
	const int *newPtr2 = (int *)&(int){2};  // initializing anonymous (int *)which is using &(int){2} which atlast is assigned to const int *newPtr2, nothing new from previous syntax just more levelling
	printf("%i\n", *newPtr);
	printf("%i\n", *newPtr2);
	const int (*newArr)[] = &(int[]){3, 4, 5};

	for (int i = 0; i < 3; ++i) {
		printf("%i\t", *(*newArr + i));  // *newArr is pointing to array of 3 blocks which is storing the address
	}
	return 0;
}

/* so, n is now 80 and so will be *ciPtr, now *ciPtr */
