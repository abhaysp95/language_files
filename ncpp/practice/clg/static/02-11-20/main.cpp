#include <iostream>
#include "util.hpp"

int statclass::A::count_;  // static member

void f1(statclass::B& o) {
	std::cout << o.var << std::endl;
}

void f1(statclass::B* o) {
	std::cout << o -> var << std::endl;
}

statclass::B f2() {
	statclass::B o;
	o.var = 10;
	return o;
}

statclass::B* f3() {
	statclass::B* o = new statclass::B();
	o -> var = 15;
	return o;
}


int main(int argc, char **argv) {
	statclass::A ob1, ob2, ob3;
	ob1.setObnum();
	ob2.setObnum();
	ob3.setObnum();
	std::cout << "Count: " << statclass::A::getCount() << std::endl;

	statclass::B obj4;
	obj4.var = 5;
	f1(obj4);

	statclass::B obj5 = f2();
	// since lifetime of o obj created by f2() is temporay you can't use
	// reference operator for obj5
	f1(obj5);

	statclass::B* obj6 = f3();
	f1(obj6);
	delete obj6;

	statclass::C obj7;
	obj7.setA(10);
	int num = 15;
	statclass::C obj8;
	obj8.setA(num);
	statclass::C* obj9 = new statclass::C();
	obj9 -> addA(obj7, obj8);
	std::cout << obj9 -> a << std::endl;
	delete obj9;
	return 0;
}
