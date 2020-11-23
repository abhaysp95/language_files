// main file

#include <iostream>

class A {
	public:
		void f1() {
			std::cout << "class A, f1()" << std::endl;
		}
};

class B: virtual public A { };

class C: virtual public A { };

class D: public B, public C {};

int main(int argc, char **argv) {
	D obd;
	obd.f1();
	return 0;
}

/* The problem happens because D creates object of B and C and B have it's own
 * copy for object of A and same stand true of C
   so, "class D -> class B -> class A and class D -> class C -> class A", so
   there are two f1() in memory and it's amibiguors to call one */

/* one way is to make f1() static */

/* basically making inheriting virtual A means if any of the A instance is
 * created that will be used by all other inheriting class of A too */