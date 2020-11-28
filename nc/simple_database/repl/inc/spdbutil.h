#ifndef SPDBUTIL_H
#define SPDBUTIL_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

/* struct for InputBuffer */
// small wrapper to interact with getline()
typedef struct {
	char* buffer;
	size_t buffer_length;
	ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

#endif
