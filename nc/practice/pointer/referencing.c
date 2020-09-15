#include <stdio.h>

int main(int argc, char **argv) {
	int p = 1, q = 2;
	int *a = &p;
	int *b = &q;
	*a = *b;
	return 0;
}
