#include <stdio.h>
#include "b_nested.h"
#include "a.h"

int main(int argc, char **argv) {
	a();
	b_nested();
	return 0;
}
