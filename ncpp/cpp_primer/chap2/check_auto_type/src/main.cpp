// main file

#include <iostream>

int main(int argc, char **argv) {
	const int i = 42;
	// top level const(in i) will be dropped -> int
	auto j = i;
	// when reference of auto type is asked top-level const(well it will not be anymore
	// a top-level const) is contained(and auto is already containing an explicti const)
	// so deduced type -> const int &k = i;
	const auto &k = i;
	// same as above const will not be dropped, and the type will be -> const int*
	auto *p = &i;
	// const from i will be dropped(top-level const) but j2 is having an explicit const
	// so deduced type -> const int j2;
	const auto j2 = i;
	// now, top-level const in initializer i will not be ignored cause we asked for
	// reference of auto deduced type so, it'll be const int&, also k2 is having
	// an explicit const of itself so type is -> const int&;
	const auto &k2 = i;

	// writing deduced types with _ as prefix
	const int _i = 42;
	int _j = i;
	const int& _k = i;
	const int* _p = &i;
	const int _j2 = i;
	const int& _k2 = i;
	return 0;
}