/* if you convert any type of object pointer into a pointer to any char type,
 * the result is a pointer to the first byte of the object */

/* TODO: checkout link provided by kernel related to kindof type conversion from C Coding group
also check what size of struct is */

#include <stdio.h>

struct Data {
	short id;
	double val;
};

int main(int argc, char **argv) {
	/*struct Data myData = {0x123, 77.7};*/
	struct Data myData = {.id = 0x123, .val = 77.7};  // from C99
	unsigned char *cp = (unsigned char *)&myData;  // pointer to first byte of structure
	printf("%p: ", cp);  // printing the starting address
	for (int i = 0; i < sizeof(myData); ++i) {
		printf("%c: %02X ", *(cp + i), *(cp + i));  // print each of the structure in hexadecimal
	}
	putchar('\n');
	return 0;
}

/* In output, the first two bytes, 23 01, shows that the code was executed on a
 * little-endian system: the byte of the lowest address in the structure myData
 * was the least significant byte of the short member id */
