/** Name -> Abhay Shanker Pathak
Date -> 2020-05-01
Description -> replace more than one blank with one
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-01 */


#include<stdio.h>

// main function <<<
int main(int argc, char* argv[]) {
	int c, num = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (num == 0) {
				putchar(c);
				num = 1;
			}
		}
		if (c != ' ') {
			num = 0;
			putchar(c);
		}
	}
		putchar(c);
	return 0;
}
// >>>
