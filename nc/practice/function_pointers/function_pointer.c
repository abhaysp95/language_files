// working examples of function pointer

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}





int compare(const void *x, const void *y) {
	float a = *(float *)x;
	float b = *(float *)y;
	return a > b ? -1 : (a == b ? 0 : 1);  // decreasing order, change to < for inc
}












void print(float *arr) {
	for (int i = 0; i < 6; ++i) {
		printf("%.2f\n", *(arr + i));
	}
}







// new
/*int func1(int (someFunc)(int, int)) {*/
	/*return someFunc(3, 5);*/
/*}*/

// old
int func1(int (*someFunc)(int, int)) {
	return someFunc(3, 5);
}






// there's now two of returning a function pointer, we can use typedef which is popular one
typedef int(*mathFunc)(int, int);
// this means, that mathFunc will return a function with return type of int and which will take two int as parameter

mathFunc func_rtn(int type) {
	// here, return type of the function func_rtn is mathFunc
	if (type == 1) {
		return add;
	}
	else {
		return sub;
	}
}

// there's another way to return to return a function pointer
/*int (*func_rtn(int type))(int, int) {
	// here, also return type is of func_rtn is of type of function pointer whose
	// return type is int and is accepting two integers as parameter
	if (type == 1) {
		return add;
	} else {
		return sub;
	}
}*/






int main(int argc, char **argv) {

	/*int (*add_ptr1)(int, int) = add;  // will work on new compiler*/
	// now, add_ptr is holding the address of add
	int (*add_ptr2)(int, int) = &add;  // works with old compiler




	/*int c = add_ptr1(1, 2);*/  // new way
	int c = (*add_ptr2)(1, 2);  // traditional way
	printf("%d\n", c);



	printf("Size of add_ptr2: %lu\n", sizeof(add_ptr2));
	printf("Size of add_ptr2: %lu\n", sizeof(*add_ptr2));



	/*int d = func1(add);*/
	/*int d = func1(add_ptr2);*/
	int d = func1(*add_ptr2);  // this as well as above two will also work,
	// because, it's add is passing it's address, and *add_ptr2 is passing
	// the address of add, and add_ptr2 is just a pointer to add function,
	// so it'll also work, cause accpeting one has type of
	// {int (int (*)(int, int))}, so add_ptr is automactically dereferenced
	printf("%d\n", d);




	/*int (*someNewFunc)(int, int) = func_rtn(1);*/
	mathFunc someNewFunc = func_rtn(1);  // both are same thing
	int e = someNewFunc(5, 8);
	printf("%d\n", e);







	// Array of function pointer
	mathFunc arr[2] = {add, sub};
	int f = (*arr[0])(2, 3);  // arr[0](2, 3); will also work(new)
	int g = (*arr[1])(5, 6);
	int h = (*(arr))(5, 6);
	int i = (*(arr + 1))(9, 6);
	printf("%d\n%d\n%d\n%d\n", f, g, h, i);

	// now creating array of function pointer without typedef
	int (*array[2])(int, int) = {add, sub};
	int j = (*array[0])(6, 7);
	int k = (*array[1])(8, 3);
	printf("%d\n%d\n", j, k);








	// quick sort in C
	float *toSort = (float *)malloc(sizeof(float) * 6);
	srand(time(NULL));
	for (int i = 0; i < 6; ++i) {
		*(toSort + i) = (float){(10 + (rand() % (10)))};  // random number bt. 10 to 20
	}
	print(toSort);

	qsort(toSort, 6, sizeof(float), compare);

	print(toSort);



	return 0;
}
