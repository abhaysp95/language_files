// show the register storage type

// Type = Register
// Storage = CPU
// Default Value = Garbage
// Scope = same as automatic
// Life = same as automatic


#include<stdio.h>

int main(int argc, char *argv[]) {
	register int i;  // same as automatic, it'll not return
	// a garbage but 0(modern compiler, maybe)
	printf("i is %d\n", i);
	for (i = 1; i <= 10; i++) {
		printf("%d\t", i);
	}
	return 0;
}

// although, we defined storage type as register, CPU registers are limited
// if all the registers are busy then the variable will be given automatic storage class
// Also, variable type more than the size of registers could not be stored in register
// then again they'll be given automatic and stored in Memory
