#include <stdio.h>
#include <unistd.h>

int main() {
	if (fork() || fork())
		fork();
	printf("hello\n");
	return 0;
}
