// demonstration of conditional compilation with macros

#include <stdio.h>
#define DO_THIS
// if not defined then statements inside 'ifdef' block willn't execute
#define SUM

int function_to_chek_ifndef_with_sum(int a, int b) {
	printf("Returning sum, so ifndef block is working\n");
	return a + b;
}

// main function
int main(int argc, char* argv[]) {
	int sum = 0;
	printf("This is general sentence\n");
# ifdef DO_THIS
	printf("This statement is inside ");
	printf("the conditional type of macro\n");
# else
	printf("Macro for ifdef block isn't defined\n");
# endif
	printf("This is the end statement\n");

	printf("Now checking ifndef block\n");
# ifndef SUM
	printf("The ifndef not macro is defined, so no sum\n");
# else
	printf("The ifndef macro is defined\n");
	sum = function_to_chek_ifndef_with_sum(4, -5);
	printf("Sum is: %d\n", sum);
# endif
	return 0;
}
