#include <iostream>

/* you use new keyword to create/store value in heap memory whose lifecycle is
 * longer than the lifecycle of function, 'new' returns a pointer to the memory
 * storing data, not the data itself */

int main(int argc, char **argv) {
	int *numptr = new int;
	/* numptr is in stack and a 'new int' memory is allocated in heap and
	 * numptr is pointing to that memory of heap, you can only have that heap
	 * memory reclaimed in the program if you pass it to 'delete'.
	 * Question ->
	 * even if the 'new int' have memory in/of heap, *numptr is in stack and
	 * that part can be reclaimed(maybe after the scope declaring function
	 * ends)? */
	std::cout << "*numptr " << *numptr << std::endl;  // 0, maybe automatic initializing it
	std::cout << "numptr " << numptr << std::endl;  // address of heap
	std::cout << "&numptr " << &numptr << std::endl;  // address of stack
	*numptr = 42;
	std::cout << "*numptr " << *numptr << std::endl;
	std::cout << "numptr " << numptr << std::endl;
	std::cout << "&numptr " << &numptr << std::endl;

	// let's check the one with stack
	int n = 7;
	int *num = &n;
	std::cout << "*num " << *num << std::endl;
	std::cout << "num " << num << std::endl;
	// from stack(addr of 7), you see it's slightly less than the address of
	// numptr in stack becuase this is declared and initialized after(I think
	// memory is allocated after initialization) and stack works as top -> down
	// approach
	std::cout << "&num " << &num << std::endl;
	delete numptr;
	/* after delete numptr, *numptr from stack is still pointing to the heap
	 * memory even though the content of data is deleted, so we should allocate
	 * numptr to nullptr, which can't be used and give segmentation fault if
	 * used */
	numptr = nullptr;  // or just numptr = 0;
	/* however, if we don't make it to nullptr program is going to exit anyway
	 * as main() ends the OS will release all the allocated memory back to
	 * system, but don't be sloppy like this */
	return 0;
}

/* generally address of stack are larger than address of heap, and heap allocates memory as bottom-up approach(low to high) */
