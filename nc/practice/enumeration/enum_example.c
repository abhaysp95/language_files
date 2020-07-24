// enum variable takes only one value

#include <stdio.h>

typedef enum {
	club = 0,
	diamond = 20,
	heart = 30,
	spade = 10
} card ;

// main function
int main(int argc, char* argv[]) {
	long unsigned card = club;
	printf("Size of diamond is: %lu\n", sizeof(card));
	// size of long unsigned int here, 8
	return 0;
}
