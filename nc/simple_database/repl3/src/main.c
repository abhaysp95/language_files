#include <stdio.h>
#include "../inc/spdbutil.h"

int main(int argc, char **argv) {
	InputBuffer* input_buffer = new_input_buffer();
	Table* table = new_table();
	while (true) {
		// read prompt input
		print_prompt();
		read_input(input_buffer);

		if (input_buffer->buffer[0] == '.') {
			/* Non-SQL statements like ".exit" are called meta command, so
			 * handling them with seperate function

			 * Using enum result codes wherever possible cause exceptions
			 are bad(and C doesn't support them)
			 */
			switch (do_meta_command(input_buffer)) {
				case (META_COMMAND_SUCCESS):
					continue;
				case (META_COMMAND_UNRECOGNIZED):
					printf("Unrecognized command '%s'\n", input_buffer->buffer);
					continue;
			}
		}

		Statement statement;
		/* convert input into internal representation of statement, consider it as front-end */
		switch (prepare_statement(input_buffer, &statement)) {
			/* compiler may complain if switch statement doesn't handle
			 * every member of enum, so handling every member */
			case (PREPARE_SUCCESS):
				break;
			case (PREPARE_SYNTAX_ERROR):
				printf("Syntax Error. Couldn't parse the statement.\n");
				break;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				printf("Unrecognized keyword at start of '%s'\n",
						input_buffer->buffer);
				continue;
		}
		/* executing the prepared statement, consider this as a simple VM */
		switch (execute_statement(table, &statement)) {
			case (EXECUTE_SUCCESS):
				printf("Executed.\n");
				break;
			case (EXECUTE_TABLE_FULL):
				printf("Error: Table full.\n");
				break;
		}
	}
	return 0;
}
