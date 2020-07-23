// show the automatic storage type

// Type = automatic storage
// Storage = Memory
// Default Value = Garbage
// Scope = Local to the block in which variable is defined
// Life = Till the control remains within the block it is defined


#include<stdio.h>

void check_i() {
	auto int i = 1;
	{
		auto int i = 2;
		{
			auto int i = 3;
			printf("%d\n", i);  // nearest to this printf is 3 in 3, 2, 1
			i++;
		}
		printf("%d\n", i);  // nearest to this printf is 2 in 2, 1
		i++;
	}
	printf("%d\n", i);  // nearest to this printf is 1 in only 1 left
	i++;
}

void increment() {
	auto int i = 1;
	printf("%d\n", i);
	i++;
}

int main(int argc, char *argv[]) {
	auto int i, j;  // modern compilers will not print garbage value(I think)
	printf("%d %d\n", i, j);
	printf("Increment function\n");
	increment();
	increment();
	increment();
	printf("check_i function\n");
	check_i();
	printf("Calling check_i function again to compare with static storage type\n");
	check_i();
	// so, it doesn't have persistance and life ends as soon as function ends
	return 0;
}
