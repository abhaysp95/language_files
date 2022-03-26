// memory segments in C

#include <stdio.h>
#include <stdlib.h>

int global_var;
int global_initialized_var = 5;

void function() {  // this is just a demo function
	int stack_var;  // same name as in the main
	printf("the function's stack var is at address 0x%08x\n", &stack_var);
}

int main() {
	int stack_var;  // same name as the variable in function
	static int static_initialized_var = 5;
	static int static_var;
	int *heap_var_ptr;

	heap_var_ptr = (int*)malloc(4);

	// these variables are in the data segment
	printf("global_initialized_var is at address 0x%08x\n", &global_initialized_var);
	printf("static_initialized_var is at address 0x%08x\n", &static_initialized_var);

	// these variables are in the bss segment
	printf("global_var is at address 0x%08x\n", &global_var);
	printf("static_var is at address 0x%08x\n", &static_var);

	// this variable is in the heap segment
	printf("heap_var is at address 0x%08x\n", &heap_var_ptr);

	// these variable are in the stack segment
	printf("stack_var is at address 0x%08x\n", &stack_var);
	function();
}
