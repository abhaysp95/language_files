/* Q1. What is function pointer? How to create them?
   A1. Function pointer store address of another function */


// Creation:

int i;
int *p = &i;  // normal pointer

int add(int a, int b) {
	return a + b;
}

int *add_ptr(int a, int b);  // this is not correct
// this is that, there's a function named add_ptr, which is returning int *

int (*add_ptr)(int , int) = add;









/* Q2. Calling a function using a function pointer
   A2. see below */

int c = add_ptr(1, 2);
// or
int c = (*add_ptr)(1, 2);











/* Q3. How to pass a function pointer as an argument to another function pointer
   A3. given below */

int func1(int (*someFunc)(int, int)) {
	return someFunc(1, 2);
}











/* Q4. How to return a function pointer
   A4. see below */
// Two ways:
// first is using typedef

typedef (int)(*someNameToCall)(int, int);
// now, this is going to be the return type of the function which is returning a function pointer

someNameToCall someName(int num) {
	if (num == 1) {
		return add;
	}
	else {
		return sub;  // create a sub function
	}
}


// second way
int (*someNameToCall(int))(int, int) {
	// do things which will return a function pointer
}












/* Q5. How to use arrays of function pointers
   A5. see below;
*/

someNewFunc arr[2] = {add, sub};
// or
int (*someNewFunc[2])(int, int) = {add, sub};


















/* Q6. Where to use function pointer
   A6. example like in qsort() */
