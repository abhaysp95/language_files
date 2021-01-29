// main file

/**
  to test the code take two files for example which should be really big
  here's the output from 'wc' for both files:
  1. first_example.txt
	lines -> 339772
	words -> 2562720
	chars -> 22933111
	size -> 22M
  2. second_example.txt
	lines -> 63114
	words -> 425343
	chars -> 3911737
	size -> 3.8M
  Above is the description of file(content) which I used for the example
  If you have any difficulty filling up the files, do this:
  $ ls -R "$HOME" > file1.txt 2>/dev/null
  $ ls -R /usr > file2.txt 2>/dev/null
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/load_file_util.h"

void print_lines1(char** words, const size_t len);
void print_lines2(char** words);

int main(int argc, char **argv) {
	if (argc == 1) {
		fprintf(stderr, "Must supply a filename\n");
		exit(1);
	}

	// load file into the data structure
	/*size_t length = 0;*/
	char** words = load_file3(*(argv + 1));
	if (!words) {
		fprintf(stderr, "Can't build the data structure\n");
		exit(1);
	}
	/*printf("\nLines in file %s is %zu\n", *(argv + 1), length);*/
	printf("\nContent of file %s is: \n\n", *(argv + 1));
	/*print_lines1(words, 200);*/
	print_lines2(words);
	return 0;
}

void print_lines1(char** words, const size_t len) {
	for (size_t i = 0; i < len; ++i) {
		printf("%s\n", *(words + i));
	}
	printf("\n");
}

void print_lines2(char** words) {
	size_t i = 0;
	while (words[i] != NULL) {
		printf("%s\n", *(words + i++));
	}
	printf("\n");
}