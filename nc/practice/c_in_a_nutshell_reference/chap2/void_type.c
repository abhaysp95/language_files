#include <stdio.h>

// if you have a function like this
// FILE *tmpfile( void );
/* then compiler definately knows that you don't have to pass any argument but if not void given then compiler gets confused */

int main(int argc, char **argv) {
	char filename[] = "memo.txt";
	if (fopen( filename, "r") == NULL) {
		perror( filename );
	}
	return 0;
}
