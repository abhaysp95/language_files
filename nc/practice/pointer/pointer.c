#include<stdio.h>
#include<stdlib.h>

#define NULL ((void*)0)	// NULL is basically just a zero casted to void pointer

typedef struct {
	int A;
	int B;
} StructType;

// main function <<<
int main(int argc, char *argv[]){
	int myvar = 13;
	int *address_myvar = &myvar;
	int arr[5] = {1, 2, 3, 4, 5};
	int *ptr = &(arr[0]);

	int var = 2;
	int *pptr = &var;
	int **preptr = &pptr;

	StructType MyStruct = {2, 5};
	StructType *MyPtr = &MyStruct;

	int *NewPtr = NULL;

	printf("variable myvar at address %p has the value %d\n", &myvar, myvar);
	printf("variable myvar at address %p has the value %d\n", address_myvar, *address_myvar);

	printf("at address '%p' we have the value '%d'\n", ptr, *ptr);
	ptr++;
	printf("at address '%p' we have the value '%d'\n", ptr + 1, *ptr + 1);
	ptr++;
	printf("at address '%p' we have the value '%d'\n", ptr, *ptr);

	printf("A of MyStruct is %d\n", MyStruct.A); // the direct access
	printf("A of Mystruct is %d\n", (*MyPtr).A); // access by dereferencing the pointer
	printf("A of MyStruct is %d\n", MyPtr -> A); // dereferencing pointer with a nicer notation

	printf("Value of pptr is %p\n", pptr);
	printf("Value of preptr is %p\n", *preptr);

	printf("NewPtr is %d\n", *NewPtr);

	return 0;
}
// >>>
