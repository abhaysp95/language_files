// external storage type demonstration

// Type = external storage
// Storage = Memory
// Default Value = Zero
// Scope = Global, but limited to a single file
// Life = As long as the program execution doesn't comes to an end


#include <stdio.h>

int i;  // declaration of external storage class variable should be done before usage
void increment();
void decrement();

// main function
int main(int argc, char* argv[]) {
	printf("\ni = %d\n", i);
	increment();
	increment();
	decrement();
	decrement();
	return 0;
}

void increment() {
	i++;
	printf("On increment: i = %d\n", i);
}

void decrement() {
	i--;
	printf("On decrement: i = %d\n", i);
}
