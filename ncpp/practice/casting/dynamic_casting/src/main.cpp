// main file

#include <iostream>

class Base {
	protected:
		int _m_value{};
	public:
		Base(int value): _m_value{value} {}
		virtual ~Base() = default;
};

class Derived: public Base {
	protected:
		std::string _m_name{};
	public:
		Derived(int value, std::string name): Base(value), _m_name{name} {}
		const std::string& getName() const { return this->_m_name; }
};

Base* getObject(bool bReturnDerived) {
	if (bReturnDerived) {
		return new Derived(1, "Apple");
	}
	else {
		return new Base(2);
	}
}

void firstAttempt() {
	Base* b{getObject(true)};
	delete b;
	// how do we print derived objects name, having only Base*

	// we'll always be getting base pointer, but this pointer could point to Base
	// or Derived object, in case of pointing to Derived object, how to call
	// Derived::getName()

	// one way will be to put virtual function in the Base class, but then what will
	// it do, if the Base pointer/reference is pointing to Base object, this isn't
	// a good solution
}

// Now, we know that C++ will let you implicitly convert the Derived pointer to Base pointer
// (just what the getObject()) is doing, this process is know as 'UpCasting'.
// But what if there was way to convert Base pointer to derived pointer, then we could
// call Derived::getName() directly using that pointer and don't have to worry about
// virtual function resolution at all

// Dynamic casting
// most common use of dynamic casting is to convert Base Class pointers to derived
// class pointers, this is knows as 'DownCasting'
// this is just like static cast
void secondAttempt() {
	Base* b{getObject(true)};
	// dynamic cast to convert Base pointer to derived pointer
	Derived* d{dynamic_cast<Derived*>(b)};
	std::cout << "The name is: " << d->getName() << "\n";
	delete b;
}

// Dynamic cast failure
// The above function works becasue Base pointer is actually pointing to Derived object
// However, this is a dangerous assumption(assumption was that d->getName() would work),
// what if b wasn't?  If getObject() return Base pointer to a Base object and we try
// to dynamic_cast it to Derived, it'll fail and the result of conversion will be null pointer
// and since we haven't checked, dereferencing(d->getName()) a null pointer could lead
// to unexpected results
// So, we need to ensure the success
void thirdAttempt() {
	Base* b{getObject(true)};
	Derived* d{dynamic_cast<Derived*>(b)};
	if (d) {  // if d is not-null
		std::cout << "The name is: " << d->getName() << "\n";
	}
	delete b;
}

// Downcasting with dynamic_cast will not work, when:
// 1. with protected or private inheritance
// 2. for classes that don't declare or inherit any virtual function, thus don't have
// any virtual table
// 3. in certain cases involving virtual base classes


// Downcasting with static_cast
// You know this from previous sub-project of static-cast
// difference is that static_cast don't ensure runtime checking of what you are doing
// is making any sense. So, static_cast is faster but more dangerous
// If you cast a Base* object to Derived* with static_cast, it'll be successful
// This will result in undefined behavior when you'll try to access the resulting
// Derived pointer(that is actually pointing to a Base Object)
// One way to ensure that you know what type of object you are pointing to is the
// use of virtual function. Here's a not so great way to do it

// doing this all the way from begining

enum class ClassID {
	base,
	derived
	// others can be added here later
};

class Base1 {
	protected:
		int _m_value{};
	public:
		Base1(int value): _m_value{value} {}
		virtual ~Base1() = default;
		virtual ClassID getClassID() const { return ClassID::base; }
};

class Derived1: public Base1 {
	protected:
		std::string _m_name{};
	public:
		Derived1(int value, std::string name): Base1(value), _m_name{name} {}
		const std::string& getName() const { return this->_m_name; }
		virtual ClassID getClassID() const { return ClassID::derived; }
};

Base1* getObject1(bool bReturnDerived) {
	if (bReturnDerived) {
		return new Derived1(10, "Mango");
	}
	else {
		return new Base1(20);
	}
}

void fourthAttempt() {
	Base1* b{getObject1(true)};
	if (b->getClassID() == ClassID::derived) {
		// we already proved, b is pointing to Derived object, so this should always succeed
		Derived1* d{static_cast<Derived1*>(b)};
	std::cout << "The name is: " << d->getName() << "\n";
	}
	delete b;
}

int main(int argc, char **argv) {
	firstAttempt();
	secondAttempt();
	thirdAttempt();
	fourthAttempt();

	// dynamic_cast can also work with references
	Derived apple{1, "Apple"};  // create an apple
	Base &b{apple};  // set base reference to apple
	Derived &d{dynamic_cast<Derived&>(b)}; // dynamic cast using reference instead of pointer
	// you can't use d for condition checking
	std::cout << "The name is: " << d.getName() << "\n";
	return 0;
}