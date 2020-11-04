#include <iostream>

class Entity {
	private:
		int x_, y_;
		int *z_;
		mutable int var;
	public:
		// this method is not gonna modify the actual class
		int getX() const {
			var = 20;  // mutable can be modified inside const
			return x_;
		}
		int getY() const { return y_; }

		int getX() { return x_; }  // no const
		int getY() { return y_; }

		// returning the pointer can't be modified, content of
		// pointer can't be modified and function can't be
		// modify to actual class
		const int* const getZ() const { return z_; }
		void setX(int x) { x_ = x; }
		void setY(int y) { y_ = y; }
};

void printEntity1(const Entity& e) {
	// can't reassign to something else to e
	//e = Entity();  // not work, cause actually changing e

	// but getX() and getY() should be const, cause not
	// modifying the entity directly but calling a method which
	// can modify the entity
	std::cout << e.getX() << std::endl;
	std::cout << e.getY() << std::endl;
}

void printEntity2(const Entity* e) {
	// can modify what's it pointing to but not the content of e
	//e = nullptr;  // will work
	std::cout << e -> getX() << std::endl;
	std::cout << e -> getY() << std::endl;
}

int main(int argc, char **argv) {
	const int MAX_AGE = 90;  // never going to change it
	int* a = new int(2);
	*a = 5;
	a = (int *)&MAX_AGE;  // breaking promise of const
	// assigning int* from const int *, so change to int*
	*a = 100;
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl;

	const int* b = new int;   // can't modify content of that pointer
	//*b = 10;  // not allowed, read-only variable*
	b = (int *)&MAX_AGE;  // so const int* can have int*
	b = &MAX_AGE;

	int* const c = new int;  // can change the content of pointer but can't reassign the pointer itself
	*c = 20;
	//c = &MAX_AGE;  // not allowed

	// and, these are same
	int const* d = new int;
	const int* e = new int;

	// so, const before pointer can't change content of the pointer and const
	// after pointer can't reassign the pointer

	const int* const f = new int;  // can't change both
	return 0;
}
