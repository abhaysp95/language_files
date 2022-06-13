#include <iostream>

/**
 * Preprocessor Operstors
 *
 * # The so-called stringification operator. Turns the argument in a string
 * literal containing its value (adds the necessary character escape sequence
 * and surrounding double quotes)
 *
 * ## The concatenation operator. Concatenates (pastes together, similar to
 * what the + operator does for the values of two std::strings) the value of
 * two identifiers
 */


/* #define DEFINE_PRINT_FUNCTION(NAME, COUNT, VALUE) \
	void NAME##COUNT { std::cout << #VALUE << std::endl; }


DEFINE_PRINT_FUNCTION(fun, 123, Test 1 "2" 3)

int main()
{
	fun123();
} */

#ifdef __has_include

#if __has_include(<cmath>)  // use it to test for something new or missing, like <optional>

void cmath_cpp();

#elif __has_include(<math.h>)

void cmath_c();

#else

#error("Need atleast <cmath> or <math.h>")

#endif

#endif
