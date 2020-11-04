#include <iostream>
#include <string>

class Entity {
	public:
		virtual std::string getName() { return "Entity Name"; }
};

class Player: public Entity {
	private:
		std::string m_Name;
	public:
		Player(const std::string& name)
			: m_Name(name) {}

		// c++11 introduced override, not necessary to use but it's a good idea to use
		std::string getName() override { return m_Name; }
};

void printName(Entity* e) {
	std::cout << e -> getName() << std::endl;
}

int main(int argc, char **argv) {
	/*Entity* e = new Entity();
	std::cout << e -> getName() << std::endl;
	Player *p = new Player("New Player");
	std::cout << p -> getName() << std::endl;*/

	// let's use concept of polymorphism here, so referring Player as Entity
	/*Entity* entity = p;
	std::cout << entity -> getName() << std::endl;  // we still get "Entity Name" as output*/

	// ok, let's make a function which takes any instance of Entity and return it's name
	Entity *e = new Entity();
	printName(e);
	Player *p = new Player("New Player");
	printName(p);  // we're getting "Entity name", not "New Player"
	// This isn't the same behaviour as java, in which method is called corresponding it's object type
	// here, it's calling according to the type

	// For this, c++ uses virtual functions
	// virtual function has a concept of dynamic dispatch, which compiles
	// implement by v-table, which consist of all the virtual mappings of our
	// base class, so they can be matched at runtime

	// virtual function does costs runtime performance, additional memory for
	// v-table and it includes the member pointer in the base class that points
	// to the v-table, and every time calling virtual function is called we
	// have to go to v-table
	return 0;
}
