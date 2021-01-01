// cpp file for "a.hpp"

#include "../inc/a.hpp"

int duplicate(int num) {
	return num * 2;
}

// this can lead to some problem if some other translation unit is dependent on
// this D and this translation unit is still not compiled(known to compiler)
// yet
int D = duplicate(8);  // D is dynamically-initialized

int& A() {
	static int a = duplicate(7);  // initialized first time A() is called
	return a;
}