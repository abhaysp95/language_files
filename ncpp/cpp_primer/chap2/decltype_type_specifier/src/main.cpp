// main file

#include <iostream>

int main(int argc, char **argv) {
	// decltype and auto both deduce the type in different manners, decltype also
	// includes top-level const unlike auto(which does it when reference of auto)
	// deduced variable is asked
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0;  // type is const int
	decltype(cj) y = x;  // type is const int&
	// decltype(cj) z;  // since z will be of type const int& it needs to be initialized

	// decltype of a expression can be a reference type
	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b;  // r will give int, and r + 0 will give int
	// decltype(*p) c;  // error: c will be int& and must be initialized
	decltype(*p) c = i;  // int& c = i;
	++c;
	std::cout << "new i is: " << i << std::endl;

	// decltype((i)) will always be &(reference) type,
	// but decltype(i) will only be reference type if i is of reference type
	// decltype((ci)) z;  // error, int& type
	decltype((ci)) z = x;
	decltype(ci) w = cj;  // int type
	return 0;
}