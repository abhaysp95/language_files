// performing multiple indirection with strings

#include <stdio.h>
#define LENGTH 3

char *words[LENGTH];
// this is like 2d-array, cause every string is also an array of char

int main() {
	char *pc;
	char **ppc;

	printf("Multiple Indirection Example\n");

	words[0] = "ZERO";
	words[1] = "ONE";
	words[2] = "TWO";

	ppc = words;  // now ppc holds the address of the array, which is address for first char in word[1]

	// ppc will not hold the address of 'Z' but will hold the address of the location(variable) which is holding the address of 'Z'
	// also, 2d-array doesn't mean 2 level indirection, remember, array is stored linearly in memory not in 2d form
	// so, ppc => some_address pointing => address of 'Z' => 'Z'
	printf("Value in ppc: %p\n", ppc);
	printf("Value to which ppc is pointing: %p\n", *ppc);
	printf("Address of first char of first string: %p\n", words[0]);
	printf("Value at the above address: %c\n", *words[0]);
	printf("One forward Address of first char of first string: %p\n", words[0] + 1);
	printf("One forward Value at the above address: %c\n", *(words[0] + 1));

	printf("\n\n--------------------------------------\n\n");

	printf("Printing each char from string now, seperated by space\n\n");

	for (int i = 0; i < LENGTH; ++i) {
		ppc = words + i;
		printf("ppc address now: %p\n", &ppc);
		printf("ppc holding now: %p\n", ppc);
		printf("ppc pointing to: %p\n\n", *ppc);
		pc = *ppc;
		while (*pc != '\0') {
			printf("pc address now: %p\n", &pc);
			printf("pc holding now: %p\n", pc);
			printf("pc pointing to: %c\n\n", *pc);
			// printf("%c ", *pc);
			pc += 1;
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
