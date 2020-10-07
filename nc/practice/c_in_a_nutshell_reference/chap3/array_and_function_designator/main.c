/* An array or function designator is any expression that has an array or
 * function type. In most cases, the compiler implicitly converts an expression
 * with an array type, such as the name of an array, into a pointer to the
 * array’s first element. The array expression is not converted into a pointer
 * only in the following cases:
	 * When the array is the operand of sizeof operator
	 * When the array is the operand of the address operator(&)
	 * When a string literal is used to initialize an array of char, wchar_t,
 * char16_t or char32_t
 */


#include <stdio.h>
#include <string.h>

void func0() {
	puts("This is the function func0().");
}

void func1() {
	puts("This is the function func1().");
}

int main(int argc, char **argv) {
	int *iPtr = 0;
	int iArray[] = {0, 10, 20};
	int array_length = sizeof(iArray) / sizeof(int);
	// in above line, iArray yields the size of whole array, not the size of
	// a pointer, but in other places(3 places) its implicitly converted to
	// a pointer
	printf("The array starts at the address %p\n", iArray);
	*iArray = 5;
	iPtr = iArray + array_length - 1;  // pointing to last element of iArray
	printf("The last element of the array is %d\n", *iPtr);

	/* The name of character arrays are used as pointers in string operations */
	char msg[80] = "I'm a string literal";
	printf("The string is %lu characters long.\n", strlen(msg));
	// msg is converted implicitly to pointer to the Array's first element
	// with function's parameter type const char *.
	printf("The array msg is %lu bytes long\n", sizeof(msg));

	/* any expression that designates a function, such as a function name,
	 * can also be implicitly converted into a pointer to the function */

	void (*funcTable[2])(void) = {func0, func1};
	// Array of two pointers to functions returning void
	// (not, pointer to Array of functions returning void)
	for (int i = 0; i < 2; ++i) {
		/*funcTable[i]();*/
		void (*element)(void) = funcTable[i];
		element();
		(*(funcTable + i))();
		// so, *(funcTable + i) is same to funcTable[i], and funcTable's
		// bot pointer are pointing to address of both the functions, so
		// that's why you can just call them with funcTable[i]
	}

	/*printf("**funcTable: %p\n", **funcTable);*/
	/*printf("*funcTable: %p\n", *funcTable);*/
	/*printf("funcTable: %p\n", funcTable);*/
	/*printf("**(funcTable + 1): %p\n", **(funcTable + 1));*/
	/*printf("*(*funcTable) + 1: %p\n", *(*funcTable) + 1);*/
	/*printf("**(funcTable) + 1: %p\n", **(funcTable) + 1);*/
	/*printf("*(funcTable + 1): %p\n", *(funcTable + 1));*/
	/*printf("funcTable + 1: %p\n", funcTable + 1);*/

	return 0;
}
