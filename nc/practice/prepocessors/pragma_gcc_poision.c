// demonstration of pragma gcc poison

#include <stdio.h>
#pragma GCC poison printf

// main function
int main(int argc, char* argv[]) {
	int a = 10;

	if (a ==  10) {
		printf("This shouldn't work");
	}
	printf("Bye!");
	return 0;
}
