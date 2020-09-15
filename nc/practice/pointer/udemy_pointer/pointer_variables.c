// initializing and using pointer variables

#include <stdio.h>

int main(int argc, char* argv[]) {
	int num;
	int *numptr;
	int num2;
	int **num3;
	num = 100;
	numptr = &num;
	num2 = *numptr;  // dereferencing operator giving data stored at the address
	// indirection -> using a pointer to access a data at the address to which pointer refers
	num3 = &numptr;
	printf("num=%d numptr=%d address of num=%d num2=%d num3=%d num3(single pointer)=%d num3(double pointer)=%d num3(address)=%d\n", num, numptr, &num, num2, num3, *num3, **num3, &num3);
	// their address have difference of 8, showing they are in size of 8-byte
	return 0;
}
