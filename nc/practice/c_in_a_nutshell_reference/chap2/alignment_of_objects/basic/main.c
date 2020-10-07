/* Every complete object type imposes a certain alignment on objects of that
 * type. In other words, the type specifies the kind of memory addresses at
 * which objects of that type can be stored */

/* C11 provides the operator _Alignof to determine a type's alignment, and the
 * specifier _Alignas to specify the alignment in an object defination */

/* The _Alignof operator, like the sizeof operator, yields a constant value with type size_t
   _Alignof(int)
*/

/* An alignment value less than or equal to _Alignof(max_align_t) is called a
 * fundamental alignment. All the fundamental types - the basic types and
 * pointer types have a fundamental alignment. The type max_align_t is defined
 * by stddef.h and it's alignment is supported in every context, including
 * dynamic memory allocation. In addition, the implementation may also support
 * alignments greater than _Alignof(max_align_t), which are known as extended
 * alignments. */

/* When an object is defined with the specifier -Alignas, it can have a stricter
 * alignment than its type requires. The form of _Alignas(type) is synonymous
 * with _Alignas(_Alignof(type)). The header file stdalign.h defines alignof and
 * alignas as synonyms for _Alignof and _Alignas. */

#include <stdio.h>

int main(int argc, char **argv) {
	printf("_Alignof(int): %lu\n", _Alignof(int));
	/*char var;*/
	/*int x;*/
	/*printf("size and align of var: %lu and %lu\n", sizeof(var), _Alignof(var));*/
	/*printf("size and align of x: %lu and %lu\n", sizeof(x), _Alignof(x));*/
	_Alignas(4) short var;  // defines var with the type short and four-byte alignment
	_Alignas(double) float x;  // defines x with the type float and the alignment of double
	printf("new size and align of var: %lu and %lu\n", sizeof(var), _Alignof(var));
	printf("new size and align of x: %lu and %lu\n", sizeof(x), _Alignof(x));
	/* note that sizeof is showing 2 and 4 for short and float, while _Alignof of is showing size 4 and double(8) */
	return 0;
}
