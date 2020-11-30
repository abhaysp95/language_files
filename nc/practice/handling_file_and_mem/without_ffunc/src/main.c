// main file

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
	int file_to_read = open("some_data.txt", O_RDONLY);
	int file_to_write = open(
			"some_written_data.txt",
			O_WRONLY | O_CREAT,
			S_IRUSR | S_IWUSR);

	if ((file_to_read == -1) || file_to_write == -1) {
		printf("One file couldn't open\n");
		return -1;
	}

	char c;
	int bytes;
	while ((bytes = read(file_to_read, &c, sizeof(c))) > 0) {
		if (c == '.') {
			c = '!';
		}
		write(file_to_write, &c, sizeof(c));
	}
	close(file_to_read);
	close(file_to_write);
	return 0;
}

/** look for memory-mapped file I/O and strace & ltrace(Jacob Sorber) */