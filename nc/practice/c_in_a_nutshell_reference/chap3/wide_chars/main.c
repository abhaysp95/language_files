#include <stdio.h>
#include <stddef.h>
#include <uchar.h>

int main(int argc, char **argv) {
	int c = '\xA3';  // symbol for pound sterling
	printf("Character: %c  Code: %d\n", c, c);
	// if characters that are not representible in a single byte, you can use wide-character constants
	wchar_t a = L'\u0100';  // in stddef.h
	// below are introduced in C11, characters of the below type are encoded in UTF-16 and UTF-32 respectively if the macro __STDC_UTF_16__ and __STDC_UTF_32__ are defined respectively
	char16_t b = u'\x3b3';  // in uchar.h
	char32_t d = U'\u27FA';  // in uchar.h
	printf("a: %c, b: %c, d: %c", a, b, d);
	return 0;
}
