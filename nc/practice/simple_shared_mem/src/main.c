// main file

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define PAGESIZE 4096

int main(int argc, char **argv) {
	int v = 5;
	uint8_t* shared_mem = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (fork() == 0) {
		v = 80;
		*shared_mem = 34;
	}
	else {
		wait(NULL);
	}
	printf("Not shared: %d\n", v);
	printf("shared: %i\n", *shared_mem);
	return 0;
}