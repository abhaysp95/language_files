// test argc and argv

#include <stdio.h>

void test_in_function(int , char **);

void test_in_function(int argc, char *argv[]) {
	printf("Moved to function\n");
	printf("Entered arguments are: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
}

int main(int argc, char *argv[]) {
	printf("Entered arguments are: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	test_in_function(argc, argv);
	return 0;
}
