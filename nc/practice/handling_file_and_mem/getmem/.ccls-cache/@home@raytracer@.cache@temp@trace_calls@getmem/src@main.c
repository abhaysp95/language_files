// main file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // brk() & sbrk()
#include <stdint.h>
#include <sys/mman.h>  // mman() & munmap()

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
	uint8_t* first = mmap((void*)0xDEADCAB, PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	uint8_t* second = mmap(NULL, PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	uint8_t* third = mmap(NULL, PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	printf("First: %p\n", first);
	printf("Second: %p\n", second);
	printf("Third: %p\n", third);
	return 0;
}



	/*for (int i = 0; i < 5; ++i) {
		char* ptr = malloc(5000);
	}*/

	/*void* first = sbrk(0);
	void* second = sbrk(4096);*/
	// modern virtual memory system use paging and page size is 4k(anything
	// other will get round of with multiple of 4)
	/*void *third = sbrk(0);*/

	/*int* ptr = (int*)third + 1;*/
	/**ptr = 0xDEAD;   // this is storing some number after the program break*/