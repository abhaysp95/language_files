/* You can explicitly convert an object pointer - that is, a pointer to a
 * complete or incomplete object type - to any other object pointer type. In
 * your program, you must ensure that your use of the converted pointer makes
 * sense */

#include <stdio.h>

int main(int argc, char **argv) {
	float f_var = 1.5F;
	long *l_ptr = (long *)&f_var;
	// Initialize a pointer to long with the address of f_var
	double *d_ptr = (double *)&l_ptr;  // by no means this means double dereferncing
	// Initialize a pointer with double with same address

	printf("The %zu bytes that represent %f, in hexadecimal: 0x%lx\n",
			sizeof(f_var), f_var, *l_ptr);

	// Using a converted pointer in an assignment can cause trouble
	/**d_ptr = 2.5;  // Don't try this! f_var's location doesn't have space for double value*/
	*(float *)d_ptr = 2.5;  // right, stores a float value in that location
	printf("new value: %f", *d_ptr);
	return 0;
}
