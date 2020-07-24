// use of enum as flags

#include <stdio.h>

enum designflag {
	UNDERLINE = 4,
	ITALIC = 2,
	BOLD = 1
} button;

// The reason why all the integral constants are power of 2 above
// UNDERLINE = 00000100
// ITALIC = 00000010
// BOLD = 00000001

// main function
int main(int argc, char* argv[]) {
	button = UNDERLINE | BOLD;
	//   00000100
	// | 00000001
	//   --------
	//   00000101
	printf("Button: %d\n", button);

	if (button & ITALIC) {
		printf("The button is also italic: %d\n", button & ITALIC);
	}
	else {
		printf("The button is not italic: %d\n", button & ITALIC);
	}
	return 0;
}
