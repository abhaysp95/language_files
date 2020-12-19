// main file

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
	fork(); // unistd.h
	printf("process id: %d\n", getpid());
	if (fork() == 0) {
		printf("I'm child with pid: %d\n", getpid());
	}
	else {
		printf("I'm parent having child, pid: %d\n", getpid());
	}
	return 0;
}