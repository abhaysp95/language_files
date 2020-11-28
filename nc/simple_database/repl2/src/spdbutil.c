#include "../inc/spdbutil.h"

// create the buffer to perform I/O operation
InputBuffer* new_input_buffer() {
	InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;
	return input_buffer;
}

// print prompt for repl
void print_prompt() {
	printf("spdb > ");
}

// take user input
void read_input(InputBuffer* input_buffer) {
  /* general syntax of getline():
   * getline(&buffer, &length, stdin);
   * and prototype for getline() is:
   * ssize_t getline(char** lineptr, size_t* n, FILE* stream);
   * &buffer -> address of first character position to store input string, not
   * the base address of buffer but of the first character of buffer(**)
   * &length -> address of variable that holds size
   * stdin -> when stdin is specified, standard input is read, else you can
   * also use getline() read the file
   * */
  ssize_t bytes_read =
      getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
  if (bytes_read <= 0) {
    printf("Error reading input\n");
    /* EXIT_FAILURE -> same as exit(1), representing failure
     * EXIT_SUCCESS -> same as exit(0), representing success
     * EXIT_SUCCESS, EXIT_FAILURE is std. way as some system actually use 0, 1
     * for opposite as said above
     * */
    exit(EXIT_FAILURE);
	}
	// Ignore trailing new line
	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}

// wrapper just checking for exit, there's room to add more functionality
MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
	if (strcmp(input_buffer->buffer, ".exit") == 0) {
		exit(EXIT_SUCCESS);
	}
	else {
		return META_COMMAND_UNRECOGNIZED;
	}
}

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
  /* using strncmp, cause there will be queries after insert, select etc. queries */
  if (strncmp(input_buffer->buffer, "insert", 6)) {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }
        if (strncmp(input_buffer->buffer, "select", 6)) {
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}
	return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement) {
	switch (statement->type) {
		case (STATEMENT_INSERT):
			printf("This is were we would do an insertion.\n");
			break;
		case (STATEMENT_SELECT):
			printf("This is were we would do a selection.\n");
			break;
	}
}

// free up memory after use
void close_input_buffer(InputBuffer* input_buffer) {
	free(input_buffer->buffer);
	free(input_buffer);
}
