// main file

#include <iostream>

class A {
	private:
		int a;
	public:
		//A() { this->a = 0; }
		A(int a) { this->a = a; }
		void f1() { std::cout << "This is f1 from A" << std::endl; }
		void f2() { std::cout << "This is f2 from A" << std::endl; }
		~A() { std::cout << "destructor of A called" << std::endl; }
};

class B: public A {
	private:
		int b;
	public:
		B(int a, int b): A(a) { this->b = b; }
		void f1() { std::cout << "This is f1 from B" << std::endl; }
		//void f2() { std::cout << "This is f2 from B" << std::endl; }
		~B() { std::cout << "destructor of B called" << std::endl; }
};

class C {
	private:
		int c;
	public:
		C(int c) { this->c = c; }
		void f1() { std::cout << "This is f1 from C" << std::endl; }
		void f2() { std::cout << "This is f2 from C" << std::endl; }
		~C() { std::cout << "destructor of C called" << std::endl; }
};

class D: public B, public C {
	private:
		int d;
	public:
		D(int a, int b, int c): B(a, b), C(c) {};
		D(int a, int b, int c, int d): B(a, b), C(c) { this->d = d; };
		//void f1() { std::cout << "This is f1 from D" << std::endl; }
		void f2() { std::cout << "This is f2 from D" << std::endl; }
		~D() { std::cout << "destructor of D called" << std::endl; }
};

int main(int argc, char **argv) {
    /* code here */
	A ob1(10);
	B ob2(20, 30);
	ob1.f1();
	//ob1.B::f1();  B is not member of A class
	ob2.f1();
	ob2.A::f1();
	std::cout << "--------------------------" << std::endl;
	D ob3(40, 50, 60);
	D ob4(40, 50, 60, 70);
	// ob3.f1();  // ambiguous, cause D have no f1() but class B and A both have f1()
	ob3.f2();
	ob3.C::f1();
	ob3.B::f1();
	ob3.B::f2();
	ob3.A::f1();
	ob3.A::f2();
    return 0;
}

// DCBABAA
/* so this is stack based, first object of A was created, then object of B
 * provided the memory of A then B, then object of D provied the memory to B
 * which created A, and then provided memory of C and then itself D, and
 * destructor will be called on reverse order, so basically LIFO */