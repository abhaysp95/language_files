// demonstration of clrscr() in gcc

#include <stdio.h>

// these are ignored
#pragma warn -rvl
#pragma warn -par
#pragma warn -rch

void clrscr(void) {
	system("clear");
}

int main() {
	clrscr();
	printf("Hello, World");
	return 0;
}
