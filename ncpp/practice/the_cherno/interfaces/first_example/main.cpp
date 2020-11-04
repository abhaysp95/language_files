#include <iostream>
#include <string>

/* pure virtual functions in C++ are just like interfaces or abstract method in java */

class Entity {
	public:
		virtual std::string getName() = 0;  // making pure virtual function, and class became abstract
};

class Player: public Entity {
	private:
		std::string m_Name;
	public:
		Player(const std::string& name)
			: m_Name(name) {}

		// this method is now must to use, since this one is pure virtual function
		std::string getName() override { return m_Name; }
};

void printName(Entity* e) {
	std::cout << e -> getName() << std::endl;
}

int main(int argc, char **argv) {
	//Entity *e = new Entity();  // allocating an object of abstract class type Entity
	Entity *e = new Player("Very New Player");
	printName(e);
	Player *p = new Player("New Player");
	printName(p);
	return 0;
}
