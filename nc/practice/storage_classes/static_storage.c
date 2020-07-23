// show the static storage type

// Type = static storage
// Storage = Memory
// Default Value = Zero
// Scope = Local to the block in which variable is defined
// Life = Value of variable persists between different function calls(until
// program ends)

// compare the increment function here, with the one in
// automatic_storage.c file

#include<stdio.h>

void increment() {
	static int i = 1;  // checked, it does have 0 as default
	printf("%d\n", i);
	i++;
}

// this will behave same as the check_i() from automatic_storage.c
void get_i() {
	static int i = 1;
	{
		static int i = 2;
		{
			static int i = 3;
			printf("%d\n", i);
			i++;
		}
		printf("%d\n", i);
		i++;
	}
	printf("%d\n", i);
	i++;
}

int main(int argc, char *argv[]) {
	printf("Increment Function");
	increment();
	increment();
	increment();
	printf("get_i function\n");
	get_i();  // 3 2 1
	printf("Calling get_i again to check value persistance\n");
	get_i();  // 4 3 2
	// so, it had the value of 4 3 2 from previous run it printed that
	// instead of new 3 2 1 again
	return 0;
}

// Unlike all variables that are defined inside a function are normally created
// on stack each time the function is called, and die as soon as the control
// goes out from the function But if variable inside the function is defined as
// 'static', then it will not be created on stack, instead they are created in
// a place in memory called 'Data Segment'. Such variable die only when the
// program execution comes to an end
