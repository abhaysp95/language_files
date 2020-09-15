// an example to show generic pointers

#include <stdio.h>
#define LENGTH 3

int data[LENGTH];  // some integers
char *words[LENGTH];  // some strings

int main(int argc, char **argv) {
	void *gp;  // generic pointer
	void *gpp;  // another generic pointer

	// enter some integers and then show the value
	for (int i = 0; i < LENGTH; ++i) {
		*(data + i) = i;
	}
	for (int i = 0; i < LENGTH; ++i) {
		printf("%d: %d\n", i, *(data + i));
	}

	printf("\n\n---------------------------------\n\n");

	// enter some strings and then show them
	*(words + 0) = "ZERO";
	*(words + 1) = "ONE";
	*(words + 2) = "TWO";
	for (int i = 0; i < LENGTH; ++i) {
		printf("%d: %s\n", i, *(words + i));
	}

	printf("\n\n---------------------------------\n\n");

	// now, using generic pointer to show the data
	gp = data;  // set generic pointer to data array
	printf("data array address is: %p\n", gp);
	printf("Item pointed to by gp now is: %d\n", *(int*)gp);
	printf("Address shown is: %p\n\n", (int*)gp);
	gp = (int*)gp + 1;
	printf("Next, item pointed to by gp now is: %d\n", *(int*)gp);
	printf("Address shown is: %p\n\n", (int*)gp);
	gp = (int*)gp + 1;
	printf("Next, item pointed to by gp now is: %d\n", *(int*)gp);
	printf("Address shown is: %p\n\n", (int*)gp);

	printf("\n\n---------------------------------\n\n");

	// now, using generic pointer to show the strings
	gpp = words;  // set generic pointer to strings array(2d-array)
	printf("words array address is: %p\n", gpp);
	printf("Item pointed by gpp now is: %s\n", *(char**)gpp);
	printf("Address shown is: %p\n\n", (char**)gpp);
	// in the next printf *(char**)gpp + 1, means you are shifting in the first indirection, not on the second level of indirection which is required for string
	printf("Next, item pointed by gpp now is: %s\n", *((char**)gpp + 1));
	// but for address you don't have to do (()) cause it's already at second level
	printf("Address shown is: %p\n\n", (char**)gpp + 1);
	printf("Next, item pointed by gpp now is: %s\n", *((char**)gpp + 2));
	printf("Address shown is: %p\n\n", (char**)gpp + 2);

	printf("\n\n---------------------------------\n\n");

	// an experiment now with for loop
	gpp = words;
	for (int i = 0; i < LENGTH; ++i) {
		gp = *(char**)gpp;  // provide the address of first level, means starting of every string
		while (*(char*)gp != '\0') {
			printf("%c ", *(char*)gp);
			gp = (char*)gp + 1;  // make gp jmp forward one block(first level of indirection)
		}
		printf("\n");
		gpp = (char**)gpp + 1;  // get the address at second level
	}

	printf("\n\n---------------------------------\n\n");

	// showing address with for loop
	gpp = words;
	for (int i = 0; i < LENGTH; ++i) {
		//printf("Adress of gpp now: %p\n", &gpp);
		// printf("Adress of gpp now: %p\n", &words + i);
		printf("Adress of gpp now: %p\n", &(char**)gpp);
		printf("Value gpp holding now: %p\n", (char**)gpp);
		printf("Value gpp pointing to currently: %p\n\n", *(char**)gpp);
		gp = *(char**)gpp;
		while (*(char*)gp != '\0') {
			printf("Address of gp now: %p\n", &gp);
			// printf("Adress of gp now: %p\n", &(*words + i));
			printf("Value gp holding now: %p\n", (char*)gp);
			printf("Value gp pointing to currently: %c\n\n", *(char*)gp);
			gp = (char*)gp + 1;
		}
		printf("\n");
		gpp = (char**)gpp + 1;
	}
	// so, gpp and gp are just a block with never changing address(for the above loop) although there value changes
	return 0;
}
