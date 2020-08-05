// showing the usage of gotoxy() in gcc

#include <stdio.h>

void gotoxy(int x, int y) {
	printf("%c[%d;%df", 0x1B, y, x);
}

// main function
int main(int argc, char* argv[]) {
	int x = 10, y = 20;
	gotoxy(x, y);  // move cursor position
	printf("Hello World");
	return 0;
}
