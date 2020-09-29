
// header guard ->  the purpose of this is to check that in a given program one
// header file is not expanded multiple times

#ifndef FUNCTIONS_H  // so, first time if not defined, do the rest of the things
#define FUNCTIONS_H

// function declaration
int add(int, int);

// macro declaration
#define ADD(n1, n2) n1 + n2

// typedef declaration
typedef struct {
	int age;
	char *name;
} person;

#endif
