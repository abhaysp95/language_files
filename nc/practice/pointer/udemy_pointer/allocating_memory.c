// allocating memory dynamically

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define LEN 100

char *string_add(char *);

char *string_add(char *astring) {
	char *s;
	s = (char *)malloc(LEN);
	strcat(s, "Hello, ");
	strcat(s, astring);
	strcat(s, "\n");
	return s;
}

int main(int argc, char **argv) {
	char *smain;
	smain = (char *)malloc(LEN);  // malloc returns generic pointers, which in turns needs pointer casting
	smain = string_add("Joey");
	printf("%s", smain);  // you don't need to do *smain
	while (*smain != '\0') {
		printf("%c", *smain);
		smain += 1;
	}
	printf(string_add("Chandler"));
	return 0;
}

/* malloc allocates the memory on the heap, the local variable declared inside
 * the function are allocated in the stack area, when exit from the function,
 * the variables from the stack are cleaned up
 * but, data inside the heap is where the global data stored in the memory,
 * data assigned to variable on the heap continues to exist even when the
 * function is exited
 */
