/** Name -> Abhay Shanker Pathak
Date -> 2020-05-01
Description -> replace tabs with \t, backspace with \b and backslash with \\
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-01 */


#include<stdio.h>

// main function <<<
int main(int argc, char* argv[]) {
	int c;
	// while ((c = getchar()) != EOF) {
	// 	if (c == '\t') {
	// 		putchar('\\');
	// 		putchar('t');
	// 		continue;
	// 	}
	// 	if (c == '\b') {
	// 		putchar('\\');
	// 		putchar('b');
	// 	}
	// 	if (c == '\\') {
	// 		putchar('\\');
	// 		putchar('\\');
	// 		continue;
	// 	}
	// 	putchar(c);
	// }
	while ((c = getchar()) != EOF) {
		switch (c) {
			case('\t'): putchar('\\'); putchar('t'); break;
			case('\b'): putchar('\\'); putchar('b'); break;
			case('\\'): putchar('\\'); putchar('\\'); break;
			default: putchar(c);
		}
	}
	return 0;
}
// >>>
