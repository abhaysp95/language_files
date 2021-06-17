#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv) {
	char str[80] = "This is a example-STRTOK-try it.";
	const char delim[2] = " ";
	char* token;
	token = strtok(str, delim);
	assert(token != NULL);
	while (token != NULL) {
		printf("%s\n", token);
		/*printf("done\n");*/
		token = strtok(NULL, delim);  // strtok maintains a static pointer to previously passed string
		// so passed NULL in place of string
	}
	return 0;
}
