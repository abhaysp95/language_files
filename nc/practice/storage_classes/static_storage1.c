// another example program to demonstrate static storage type


#include<stdio.h>

int *func();

// pointer function
int *func() {
	static int k = 35;  // if not used static then warning is given
	// function returns address of local variable
	return ( &k );
}

// main function
int main(int argc, char* argv[]) {
	int *j;
	j = func();
	printf("%d\n", *j);
	return 0;
}
