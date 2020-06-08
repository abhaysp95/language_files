/**
    _    ____  ____
   / \  / ___||  _ \   Abhay Shanker Pathak
  / _ \ \___ \| |_) |  abhaysp9955@gmail.com
 / ___ \ ___) |  __/   https://github.com/coolabhays
/_/   \_\____/|_|

get output of following program */


#include<stdio.h>

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

// main function
int main(int argc, char* argv[]) {
	int i = 10, j, k;
	j = 5;
	k = 0;
	k = MAX(++i, j++);
	// macro works differently than functions, so if you pass ++i to x, it will
	// evluated two times in ternary operation, unlike function where it'll be
	// evluated only once inside parameter
	printf("%d %d %d", i, j, k);
	return 0;
}
