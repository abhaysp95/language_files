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

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

// currently our prepared statement just have only two possible values
typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} StatementType;

typedef struct {
	StatementType type;
} Statement;

InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
MetaCommandResult do_meta_command(InputBuffer* input_buffer);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement *statement);
void execute_statement(Statement* statement);
void close_input_buffer(InputBuffer* input_buffer);

#endif
