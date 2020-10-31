#include <stdio.h>
#include <stdint.h> // for intptr_t(signed) and uintptr_t(unsigned)

int main(int argc, char **argv) {
	float x = 1.5f, *fPtr = &x;

	// save the pointer's value as an integer
	unsigned long long addr_val = (unsigned long long)fPtr;
	printf("%ld\n", addr_val);
	// When you convert a pointer to an integer type whose range is not
	// large enough to represent the pointer's value, the result is
	// undefined.

	// or if stdint.h has been included and uintptr_t is defined:
	uintptr_t adr_val = (uintptr_t)fPtr;
	printf("%ld\n", adr_val);

	/*
	 * On an Intel x86 PC in DOS, the BIOS data block begins at the
	 * address 0x0040:0000. The first two-byte word at that address
	 * contains the I/O address of the serial port COM1.
	 * (Compile using DOS's "large" memory model.)
	 */

	unsigned short *biosPtr = (unsigned short *)0x400000L;
	unsigned short com1_io = *biosPtr;
	printf("COM1 has the I/O base address %Xh.\n", com1_io);
	return 0;
}

/*  Conversely, converting an integer into pointer type does not necessarily
 * yield a valid pointer. The header file stdint.h may optionally define the
 * integer types intptr_t(signed) and uintptr_t(unsigned). Any valid pointer can
 * be converted to either of these types, and a subsequent conversion back into
 * a pointer is guarenteed to yield the orignal pointer */
