#include <iostream>

class Entity {
	public:
		float x, y;

		Entity(float x, float y) {
			this -> x = x;
			this -> y = y;
			std::cout << "Entity created" << std::endl;
		}

		/* there's also default constructor in C++ like java, but unlike java
		 * it doesn't do anything */

		/* you can multiple constructors(overloading) */

		/* Destructors */
		~Entity() {
			std::cout << "Entity destroyed" << std::endl;
		}

		void print() {
			std::cout << x << ", " << y << std::endl;
		}
};

void function() {
	Entity e(4.5f, 5.2f);
	std::cout << e.x << std::endl;
	e.print();
}
// when stack for function() is destroyed(goes out of scope) destructor is called

int main(int argc, char **argv) {
	function();
	return 0;
}
