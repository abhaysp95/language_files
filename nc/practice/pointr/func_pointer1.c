/** Name -> Abhay Shanker Pathak
Date -> 2020-04-05
Description -> Example 1 for function pointer
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-04-05 */

#include<stdio.h>

/* void fun(int ); */

// fun function <<<
void fun(int a) {
	printf("Value of 'a' is %d.\n", a);
}
// >>>

// main function <<<
int main(int argc, char *argv[]){
	// func_ptr is a pointer to function fun()
	void (*func_ptr)(int) = &fun;

	/* The above line is equivalent to following two lines:
	   void (*func_ptr)(int);
	   func_ptr = &fun;
	*/
	// Invoking fun() using fun_ptr
	(*func_ptr)(10);

	return 0;
}
// >>>

/* int main() { */
/* 	fun(10); */
/* 	return 0; */
/* } */

/* void fun(int n) { */
/* 	printf("Value of 'a' is %d", n); */
/* } */
