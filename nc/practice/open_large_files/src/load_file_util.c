// c file for load_file_util.h

#include "../inc/load_file_util.h"

#include <stdlib.h>
#include <string.h>

extern const size_t STEPSIZE;

char** load_file1(char* filename, size_t* len) {
	FILE *f = fopen(filename, "r");
	if (!f) {  // if failed in file opening
		fprintf(stderr, "Error in opening %s file\n", filename);
		return NULL;
	}

	// allocate space for 100 char*(at starting suppose there would be 100 lines)
	// since file is supposed to be large
	char** lines = (char**)malloc(sizeof(*lines) * 100);

	size_t arr_len = STEPSIZE;
	char buf[1000];  // a temporary block to store a string
	size_t count = 0;

	while (fgets(buf, 1000, f)) {
		// check if array is full
		if (count == arr_len) {
			arr_len += STEPSIZE;
			char** newlines = realloc(lines, arr_len * sizeof(char*));
			if (!newlines) {
				fprintf(stderr, "Can't realloc\n");
				exit(1);
			}
			lines = newlines;
		}
		// trim of the newline char from strings
		// newline character will be at the length of the string index - 1
		buf[strlen(buf) - 1] = '\0';

		// get length of buffer
		size_t str_len = strlen(buf);

		// allocate space for string(+ 1 is for null character)
		char* str = (char*)malloc((str_len + 1) * sizeof(char));

		// copy string from buf to str
		strncpy(str, buf, str_len + 1);

		// attach str to data structure
		lines[count++] = str;
	}
	// set the length of the array of char*(lines)
	*len = count;
	return lines;
}

char** load_file2(char* filename, size_t* len) {
	FILE *f = fopen(filename, "r");
	if (!f) {  // if failed in file opening
		fprintf(stderr, "Error in opening %s file\n", filename);
		return NULL;
	}

	// if we pass NULL to realloc it behaves same as malloc, so let's do cleaning
	// a little bit from load_file1()
	char** lines = NULL;

	size_t arr_len = 0;
	char buf[1000];  // a temporary block to store a string
	size_t count = 0;

	while (fgets(buf, 1000, f)) {
		// check if array is full
		if (count == arr_len) {
			arr_len += STEPSIZE;
			// lines will be initially NULL so realloc will behave like malloc but
			// when it's not it'll work as realloc as it is
			char **newlines =
				realloc(lines, arr_len * sizeof(char *));
			if (!newlines) {
				fprintf(stderr, "Can't realloc\n");
				exit(1);
			}
			lines = newlines;
		}
		// trim of the newline char from strings
		// newline character will be at the length of the string index - 1
		buf[strlen(buf) - 1] = '\0';

		// get length of buffer
		size_t str_len = strlen(buf);

		// allocate space for string(+ 1 is for null character)
		char* str = (char*)malloc((str_len + 1) * sizeof(char));

		// copy string from buf to str
		strncpy(str, buf, str_len + 1);

		// attach str to data structure
		lines[count++] = str;
	}
	// set the length of the array of char*(lines)
	*len = count;
	return lines;
}

char** load_file3(char* filename) {
	FILE *f = fopen(filename, "r");
	if (!f) {  // if failed in file opening
		fprintf(stderr, "Error in opening %s file\n", filename);
		return NULL;
	}

	// if we pass NULL to realloc it behaves same as malloc, so let's do cleaning
	// a little bit from load_file1()
	char** lines = NULL;

	size_t arr_len = 0;
	char buf[1000];  // a temporary block to store a string
	size_t count = 0;

	while (fgets(buf, 1000, f)) {
		// check if array is full
		if (count == arr_len) {
			arr_len += STEPSIZE;
			// lines will be initially NULL so realloc will behave like malloc but
			// when it's not it'll work as realloc as it is
			char **newlines = (char**)realloc(lines, arr_len * sizeof(char *));
			if (!newlines) {
				fprintf(stderr, "Can't realloc\n");
				exit(1);
			}
			lines = newlines;
		}
		// trim of the newline char from strings
		// newline character will be at the length of the string index - 1
		buf[strlen(buf) - 1] = '\0';

		// get length of buffer
		size_t str_len = strlen(buf);

		// allocate space for string(+ 1 is for null character)
		char* str = (char*)malloc((str_len + 1) * sizeof(char));

		// copy string from buf to str
		strncpy(str, buf, str_len + 1);

		// attach str to data structure
		lines[count++] = str;
	}
	// set the length of the array of char*(lines)
	if (count == arr_len) {
		char** new_arr = (char**)realloc(lines, arr_len + 1 * sizeof(char*));
		if (!new_arr) {
			fprintf(stderr, "Can't put NULL at the end of lines array");
			exit(1);
		}
		lines = new_arr;
	}
	lines[count] = NULL;
	return lines;
}

