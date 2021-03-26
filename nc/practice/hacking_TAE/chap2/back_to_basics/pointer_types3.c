#include <stdio.h>

int main() {
	int i;
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	char* char_pointer;
	int* int_pointer;

	char_pointer = (char*)int_array;  // typecast
	int_pointer = (int*)char_pointer;

	// this typecasting(above 2 lines) probably only make difference on what
	// type of data_type block is holding the address for the start of what type
	// of array, and not the actual content

	for (i = 0; i < 5; ++i) {
		printf("[integer pointer] points to %p, which contains char '%c'\n",
				int_pointer, *int_pointer);
		int_pointer = (int*)((char*)int_pointer + 1);
	}

	for (i = 0; i < 5; ++i) {
		printf("[char pointer] points to %p, which contains integer '%d'\n",
				char_pointer, *char_pointer);
		char_pointer = (char*)((int*)char_pointer + 1);
	}

	return 0;
}
