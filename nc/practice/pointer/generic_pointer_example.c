/* Generic Pointers:-
 * when a variable is being declared as a pointer to the type 'void', it is
 * known as 'generic pointer'. Since, you can't have any variable of type void,
 * the pointer will not point to any data and therefore can't be dereferenced.
 * It's still a pointer though, to use it you just have to cast it to another
 * type of pointer first.
 * This is very useful when you want a pointer to point a data of different
 * types at different times
 */

#include <stdio.h>

int main(int argc, char **argv) {
	int i = 0;
	char c = '\0';
	void *the_data;  // generic pointer

	i = 5;
	c = 'a';

	the_data = &i;
	printf("Current thing is 'the_data' is: %d\n", *(int *)the_data);

	the_data = &c;
	printf("Current thing is 'the_data' is: %c\n", *(char *)the_data);
	return 0;
}
