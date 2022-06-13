#define TEST_FUNCTION  // uncomment to get trace output

#ifdef TEST_FUNCTION
#include <iostream>  // only required for trace output
#endif

#include "functions.h"

int fun::sum(int a, int b)
{
	int res {a + b};
#ifdef TEST_FUNCTION
	std::cout << "res(sum): " << res << std::endl;
#endif
	return a + b;
}

int fun::difference(int a, int b)
{
	int res {a - b};
#ifdef TEST_FUNCTION
	std::cout << "res(difference): " << res << std::endl;
#endif
	return a - b;
}

int fun::product(int a, int b)
{
	int res {a * b};
#ifdef TEST_FUNCTION
	std::cout << "res(product): " << res << std::endl;
#endif
	return a * b;
}
