#include <stdio.h>

int main() {
	int i;
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	unsigned int non_pointer;

	non_pointer = (unsigned int)char_array;
	// that's just changing the address to unsigned int

	for (i = 0; i < 5; ++i) {
		printf("[non_pointer] points to %p, which contains the char '%c'\n",
				non_pointer, *((char*)non_pointer));
		non_pointer += sizeof(char);
	}

	non_pointer = (unsigned int)int_array;

	for (i = 0; i < 5; ++i) {
		printf("[non_pointer] points to %p, which contains the integer '%d'\n",
				non_pointer, *((int*)non_pointer));
		non_pointer += sizeof(int);
	}

	return 0;
}
