// main file

/* code snippet to ensure no buffer overflow when asking information from user */

#include <stdio.h>
#include <string.h>

typedef enum {
	OK,
	NO_INPUT,
	TOO_LONG,
	SMALL_BUFF
} EntryStatus;

static EntryStatus my_getline(char* prompt, char* buffer, size_t size);

static EntryStatus my_getline(char* prompt, char* buffer, size_t size) {
	int ch, extra;

	/* size zero or one cannot store enough, so don't even try,
	   we need space for atleast newline and terminator */
	if (size < 2) {
		return SMALL_BUFF;
	}

	// output prompt
	if (prompt != NULL) {
		printf("%s", prompt);
		fflush(stdout);  // flush the stream(stdout)
	}

	// get line with buffer overrun protection
	if (fgets(buffer, size, stdin) == NULL) {
		return NO_INPUT;
	}

	// catch the possiblity of '\0' in the input stream
	size_t len = strlen(buffer);
	if (len < 1) {
		return NO_INPUT;
	}

	/* if it was too long, there'll be no newline. In that case,
	   we flush to end of line so that excess doesn't affect the
	   next call */
	if (buffer[len - 1] != '\n') {
		extra = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF)) {
			extra = 1;
		}
		return extra == 1 ? TOO_LONG : OK;
	}

	// otherwise remove newline and give string back to caller.
	buffer[len - 1] = '\0';
	return OK;
}

int main(int argc, char **argv) {
	int rc;
	char buff[10];

	rc = my_getline("Enter String> ", buff, sizeof(buff));
	if (rc == NO_INPUT) {
		// Extra new line, since my system doesn't adds it on EOF
		printf("\nNo input\n");
		return 1;
	}

	if (rc == TOO_LONG) {
		printf("Input too long [%s]\n", buff);
		return 1;
	}
	printf("OK [%s]\n", buff);
    return 0;
}


/* Visit: https://stackoverflow.com/questions/2430303/disadvantages-of-scanf  to see how to perform test_run for the code */