#include <stdio.h>
#include "../inc/spdbutil.h"

int main(int argc, char **argv) {
	InputBuffer* input_buffer = new_input_buffer();
	while (true) {
		// read prompt input
		print_prompt();
		read_input(input_buffer);

		// check if user entered ".exit"
		if (strcmp(input_buffer->buffer, ".exit") == 0) {
			close_input_buffer(input_buffer);
			exit(EXIT_SUCCESS);
		}
		else {
			printf("Unrecognized command '%s'.\n", input_buffer->buffer);
		}
	}
	return 0;
}
