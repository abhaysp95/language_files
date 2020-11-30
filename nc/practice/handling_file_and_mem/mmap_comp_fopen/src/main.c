// main file

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

float time_diff(struct timeval* start, struct timeval* end) {
	return ((end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec));
}

void test1(char* filename) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	int fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR);  // fcntl.h, sys/stat.h
	struct stat sb;
	if (fstat(fd, &sb) == -1) {  // sys/stat.h
		perror("Can't get file size\n");
		exit(EXIT_FAILURE);
	}
	char* file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);  // sys/mman.h
	srand(time(0));  // stdlib.h
	for (int i = 0; i < 50; ++i) {
		int index = rand() % sb.st_size;
		printf("%c", file_in_memory[index]);
	}
	munmap(file_in_memory, sb.st_size);  // sys/mman.h
	close(fd); // unistd.h
	gettimeofday(&end, NULL);
	printf("\nTime taken: %0.6f\n", time_diff(&start, &end));
}

void test2(char* filename) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	FILE* fp = fopen(filename, "r");
	struct stat sb;
	if (stat(filename, &sb) == -1) {
		perror("Can't get file size.\n");
		exit(EXIT_FAILURE);
	}
	srand(time(0));
	for (int i = 0; i < 50; ++i) {
		int index = rand() % sb.st_size;
		fseek(fp, index, SEEK_SET);
		printf("%c", fgetc(fp));
	}
	fclose(fp);
	gettimeofday(&end, NULL);
	printf("\nTime taken: %0.6f\n", time_diff(&start, &end));
}

int main(int argc, char **argv) {
	test2(*(argv + 1));
	printf("\n------------------\n");
	test1(*(argv + 1));
	return 0;
}

/* in main function changing the position of function effects the speed */