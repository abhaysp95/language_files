/** Name -> Abhay Shanker Pathak
Date -> 2020-05-01
Description -> another method for word count program
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-01 */


#include<stdio.h>

#define IN 1
#define OUT 0

// main function <<<
int main(int argc, char* argv[]) {
	int c, nl, nw, nc, state;
	nl = nw = nc = 0;

	state = OUT;
	while((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		// if (c == ' ' || c == '\n' || c == '\t') {
		// 	state = OUT;
		// }
		// else if (state == OUT) {
		// 	state = IN;
		// 	++nw;
		// }
		if (c == ' ' || c == '\n' || c == '\t') {
			++nw;
		}
	}
	printf("%d %d %d", nc, nw, nl);
	return 0;
}
// >>>
