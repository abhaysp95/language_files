#include <iostream>

class A {
	public:
		int var, dvar;
		static int svar;  // static member -> single copy
		static int* pvar;
		static void f1() {
			int a = 1;
			std::cout << "f1 called, a = " << a++ << std::endl;
		}
		void f2() {
			int a = 1;
			std::cout << "f2 called, a = " << a++ << std::endl;
		}
};

int A::svar;  // necessary to declare outside class
int* A::pvar;
int main(int argc, char **argv) {
	A::svar = 3;
	std::cout << A::svar << std::endl;

	A a;
	A *b = new A;
	A c;
	a.var = 10;
	A::pvar = &a.var;


	b -> var = *A::pvar;
	// b -> var, it is just normal b.var with b in heap, don't complicate this
	// with thinking like it's(b -> var) a pointer
	b -> dvar = A::svar;
	b -> pvar = &A::svar;
	b -> svar = *A::pvar;
	b -> pvar = A::pvar;

	std::cout << a.var << std::endl;
	std::cout << *A::pvar << std::endl;
	std::cout << b -> var << std::endl;
	std::cout << b -> dvar << std::endl;
	std::cout << *b -> pvar << std::endl;
	std::cout << b -> svar << std::endl;
	std::cout << *b -> pvar << std::endl;

	a.f1();
	b -> f1();
	c.f1();
	a.f2();
	b -> f2();

	return 0;
}
