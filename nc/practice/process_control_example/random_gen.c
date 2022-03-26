#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	srand(getpid());
	for (int i = 0; i < 10; ++i) {
		long int num = rand() % 1000000000;
		printf("%ld\n", num);
	}
	return 0;
}
