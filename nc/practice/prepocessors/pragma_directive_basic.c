// demonstration of basic usage of #pragma directive
// This directive is used to turn on/off some specific feature
// This type of directive is compiler specific


#include <stdio.h>

#pragma startup func1
#pragma exit func2

void func1() {
	printf("Inside func1\n");
}

void func2() {
	printf("Inside func2\n");
}

// main function
int main(int argc, char* argv[]) {
	printf("Inside main\n");
	return 0;
}

// This will only give output: Inside main
// because, gcc doesn't support #pragma startup and exit
// see gcc version for gcc


// More on pragmas

// There's #pragma warn directive
// #pragma warn -rvl  /* return value */
// #pragma warn -par  /* parameter never used */
// #pragma warn -rch  /* unreachable code */
// - is used to suppress, + is to show and . is to toggle

// There's #pragma GCC poison to remove an indentifier completely from program

// #pragma GCC dependency <file_as_dependency>, allows you to check the
// relative dates of the current file and another file. If the another file is
// more recent than the current file, a warning is issued. This is useful if
// the current file is derived from the other file, and should be regenerated.

// #pragma GCC system_header, takes no argument, causes the
// rest of the code in the current file to be treated like
// it came from a system header


// #pragma once, the header file containing this directive is included only
// once even if the programmer includes it multiple times during a compilation
// This directive works similar as #include guard idiom.
