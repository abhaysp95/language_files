// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fun1(const char* a, const char* b) {
	return strcmp(a, b);
}

int main(int argc, char **argv) {
	char* temp = calloc(20, sizeof(char));
	char* temp2 = calloc(20, sizeof(char));
	scanf("%s", temp);
	scanf("%s", temp2);
	if (fun1(temp, temp2)) {
		printf("success\n");
	}
	else {
		printf("failed\n");
	}
    return 0;
}