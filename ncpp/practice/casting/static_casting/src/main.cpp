// main file

// static casting is done during compile time
// we can cast between primitive data-types, pointers, references and also
// through inheritance
// we can do common C-type casting using static_cast()


#include <iostream>

void check_addition() {
	int a = 5;
	float b = 23.90;
	// some weird casting done on compile time with static cast
	float result = static_cast<size_t>(a - b);
	std::cout << result << "\n";
}

template <class T>
bool isVoid(T *t) { return false; }  // normal case returns false

template <>
bool isVoid(void *t) { return true; }  // but if void*, return true

void check_pointer() {
	// C-style casting to convert string constant to char array
	char* arr = (char*)"This is a string";
	// using static_cast to cast to convert to a void pointer
	void* ptr = static_cast<void*>(arr);
	std::cout << "\nIs this void* ptr: " << (isVoid(ptr) ? "yes" : "no") << "\n";
	// convert back to char*
	std::cout << static_cast<char*>(ptr) << "\n";

	// static_cast() ensures that all the casting is done at compile time, so there
	// is no run-time overhead with this function, unlike other casts like dynamic_cast()
}

// casting through inheritance(provided that derived class is inherited publicly)
class BaseClass {
	public:
		int a, b;
		BaseClass(int val_a = 100, int val_b = 200): a{val_a}, b{val_b} {}
		void printObj() {
			std::cout << "BaseClass: a -> " << this->a << ", b -> " << this->b << "\n";
		}
		~BaseClass() {}
};

class DerivedClass: public BaseClass {
	public:
		int c;
		// btw, to pass the value to parent constructor, you would do like this
		//DerivedClass(int a, int b, int c): BaseClass(a, b) { this->c = c; }
		//or
		//DerivedClass(int a, int b, int c): BaseClass(a, b), c{c} {}
		DerivedClass(int val_c = 300) { this->c = val_c ; }
		void printObj() {
			std::cout << "DerivedClass: a -> " << this->a << ", b -> " << this->b << ", c -> " << this->c << "\n";
		}
		~DerivedClass() {}
};

int main(int argc, char **argv) {
	check_addition();
	check_pointer();

	std::cout << "\n";

	// we can only cast through inheritance, if we use pointers
	// otherwise, you need to construct the type conversion methods yourself
	BaseClass* base_obj = new BaseClass(20, 25);
	DerivedClass* derived_obj = new DerivedClass(10);
	base_obj->printObj();
	derived_obj->printObj();

	// cast downwards -> can do this only, if you are not using virtual inheritance
	DerivedClass* base_to_derived = static_cast<DerivedClass*>(base_obj);
	std::cout << "after casting base class object to derived class object: \n";
	base_to_derived->printObj();

	// cast upwards -> redundent(cause, if you don't compiler will do it already, I think)
	BaseClass* derived_to_base = static_cast<BaseClass*>(derived_obj);
	std::cout << "after casting derived class object to base class object: \n";
	derived_to_base->printObj();

	// we can also do reverse, but task is redundant due to inheritance

	// free the pointers
	delete base_obj;
	delete derived_obj;
	return 0;
}