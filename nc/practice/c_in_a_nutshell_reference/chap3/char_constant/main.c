#include <stdio.h>

int c = 0;
c = getchar();  // Read a character
if ((c != EOF) && c > '0' && c < '6') {
	printf("You entered: %c\n", c);
}
