/* you can explicitly convert a pointer to a given function into a pointer to a
 * function of different type */

/* In the following example, the typedef statement defines a name for the type
 * "function that has one double parameter and returns a double value" */

#include <stdio.h>
#include <math.h>

typedef double (func_t)(double);  // define a type named func_t
typedef double (func1_t)(double, double);

int main(int argc, char **argv) {
	func_t *pFunc = sqrt;  // a pointer to func_t, initialized with address of sqrt()
	double y = pFunc(2.0);  // A correct function call by pointer
	printf("The square root of 2 is %f.\n", y);
	pFunc = (func_t *)pow;  // change the pointer's value to the address of pow()

	/*y = pFunc(2.0, 2);*/
	/* can't do the above line, because pow expects 2 args, while func_t type takes only one */
	func1_t *pFunc1 = pow;
	y = pFunc1(2.0, 3);
	printf("The square of 2 is %f.\n", y);

	return 0;
}
