/** Name -> Abhay Shanker Pathak
Date -> 2020-05-01
Description -> count words
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-01 */


#include<stdio.h>

// main function <<<
int main(int argc, char* argv[]) {
	int c, nw = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			++nw;
		}
	}
	printf("count of word is: %d", nw);
	return 0;
}
// >>>
