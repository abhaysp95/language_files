// example for enum

#include <stdio.h>

enum week {
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

// main function
int main(int argc, char* argv[]) {
	enum week today;
	today = Wednesday;
	printf("Day: %d\n", today + 1);
	return 0;
}
