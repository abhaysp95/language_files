#include <iostream>

void function() {
	static int i = 0;
	// it's lot similar if we had just moved int i = 0; to global scope, but
	// this can be changed by other funcitons, which is not true with this case
	i++;
	std::cout << i << std::endl;
}


// we can do something like this with singleton(having one instance in existance) without using static local scope thing
class Singleton {
	private:
		static Singleton* s_Instance;
	public:
		static Singleton& Get() { return *s_Instance; }

		void hello() { std::cout << "this is hello" << std::endl; }
};

// declare the instance
Singleton* Singleton::s_Instance = nullptr;
// type of s_Instance is Singleton*


// or another way
class AnotherSingleton {
	public:
		static AnotherSingleton& Get() {
			static AnotherSingleton s_Instance;
			// if you don't have static in the above line, as soon as this
			// scope is left, s_Instance is destroyed from stack
			return s_Instance;
		}

		void hello() { std::cout << "this is hello" << std::endl; }
};

int main(int argc, char **argv) {
	function();
	function();
	function();
	function();
	function();
	Singleton::Get().hello();
	AnotherSingleton::Get().hello();
	return 0;
}
