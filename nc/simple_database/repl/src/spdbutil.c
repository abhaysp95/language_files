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
  size_t bytes_read =
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

// free up memory after use
void close_input_buffer(InputBuffer* input_buffer) {
	free(input_buffer->buffer);
	free(input_buffer);
}
