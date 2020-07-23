// another example of external storage

#include <stdio.h>

int x = 10;
void display();

// main function
int main(int argc, char* argv[]) {
	int x = 20;
	printf("Inside main: x = %d\n", x);  // local got precedence
	display();
	return 0;
}

void display() {
	printf("Inside display: x = %d\n", x);  // used global x
}
