// enum type

#include <stdio.h>

enum color { black, red, green = 3 };
enum signal { on, off, stop = 1, cont = 0 };
int main(int argc, char **argv) {
	enum color bgcolor = black;
	enum signal state = on;
	enum signal state1 = cont;
	printf("%d\n", bgcolor);
	printf("%d\n", state);
	printf("%d\n", state1);
	return 0;
}
