#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

void increment(int* value) {
	(*value)++;
}

void decrement(int& value) {
	value--;
}

int main(int argc, char **argv) {

	/*   Pointers   */

	void *ptr = 0;  // this just means that we don't care of the data type of whose address we are storing
	// 0 isn't a valid address
	void *ptr1 = NULL;  // is same to putting 0, as #define NULL 0
	void *ptr2 = nullptr;  // introduced in c++11

	int val = 8;
	void *ptr3 = &val;
	//int *ptr4 = &(int){8};
	//const int *newPtr =  &(int){3};  // since, C99, doesn't works in C++ though
	const int *ptr5 = &static_cast<const int &>(3);

	double *ptr6 = (double *)&val;

	// allocate a memory of certain size by asking compiler
	char* buffer = new char[8];  // 8 bytes of memery and returning pointer to the begining of the block of memory
	memset(buffer, 0, 8);  // <cstring>
	char** ptr7 = &buffer;
	delete[] buffer;


	/*   References   */
	int a = 6;
	LOG(a);
	int& ref = a;  // ref is kindof an alias, it's not another variable
	ref = 2;  // changes a to 2
	LOG(a);
	increment(&a);
	LOG(a);
	decrement(a);
	LOG(a);

	// pointers are more powerful than references, however references are more cleaner

	int b = 10;
	ref = b;  // you can't change ref to whom it's referring to after first time, this essentially means a = b;i
	LOG(a);

	// unlike pointer
	int *ref = &a;
	ref = &b;  // ref is pointing to b, not changing value(you need to do dereferencing for it)

	// also, &ref must be initialized

	return 0;
}
