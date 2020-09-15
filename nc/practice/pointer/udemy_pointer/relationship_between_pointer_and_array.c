// we are using array of char(string) here

#include <stdio.h>

// since, name of the array is also the address of the array, so
// **argv = *argv[]
int main(int argc, char **argv) {
	char hey[] = "Hello, World";
	printf("String -> %s\n", hey);
	printf("First char -> %c\n", hey[0]);
	printf("Address of array -> %d\n", &hey);
	printf("Address of first char of array -> %d\n", &hey[0]);
	printf("Again, address of array -> %d\n", hey);
	printf("Next element's address of array -> %d\n", hey + 1);
	printf("Again, first char of array -> %c\n", *hey);
	printf("Second element of array -> %c\n", hey[1]);
	printf("Second element of array -> %c\n", *(hey + 1));  // char used 8-bit
	printf("Third element of array -> %c\n", *(hey + 2));  // char used 8-bit
	printf("---------------------------------\n");
	return 0;
}
