// main file

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>

float tdiff(struct timeval* start, struct timeval* end) {
	return ((end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec));
}

int main(int argc, char **argv) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	if (argc < 2) {
		perror("Provide filename with argument\n");
	}
	int fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	struct stat sb;

	if (fstat(fd, &sb) == -1) {
		perror("Error getting file size\n");
	}
	printf("File size is %ld bytes.\n\n", sb.st_size);
	/* get block from file by reading and is private(visible to just process) */
	/*char* file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);*/

	/* if you don't make it shared changes will not be seen by other processes
	   in other words, file will not be updated */
	char* file_in_memory = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("Printing file as an array character...\n");
	for (int i = 0; i < sb.st_size; ++i) {
		if (i % 2 == 0) {
			file_in_memory[i] = toupper(file_in_memory[i]);
		}
		printf("%c", file_in_memory[i]);
	}
	munmap(file_in_memory, sb.st_size);
	close(fd);
	gettimeofday(&end, NULL);
	printf("\nTotal time taken: %0.6f\n", tdiff(&start, &end));
	return 0;
}