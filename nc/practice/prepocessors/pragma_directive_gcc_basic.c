// This is for gcc

#include <stdio.h>

void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();


void func1() {
	printf("Inside func1()\n");
}

void func2() {
	printf("Inside func2()\n");
}

// main function
int main(int argc, char* argv[]) {
	printf("Inside main()\n");
	return 0;
}
