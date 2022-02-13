#include <iostream>
#include <string>
#include <cstring>

// maximum of two values of any type
template<typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

// maximum of two pointers
template<typename T>
T* max(T* a, T* b)
{
	return *b < *a ? *a : *b;
}

// maximum of two c-strings
char const* max(char const* a, char const* b)
{
	return strcmp(b, a) < 0 ? a : b;
}

int main() {
	// put stuff here
	return 0;
}
