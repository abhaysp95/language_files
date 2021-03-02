// main file

#include <iostream>
#include <string>

class ClassName {
	public:
		virtual std::string get_class_name() const = 0;
};

class Entity: public ClassName {
	// even though you inherit ClassName, you can't still make the object of
	// cause if you don't override the pure virtual function from base class(abstract)
	// your class will also be abstract one(can't create object)
	// Entity
	public:
		//virtual std::string get_name() const { return "Entity"; }
		// make this pure virtual
		virtual std::string get_name() const = 0;
		virtual std::string another_name() const = 0;
		virtual std::string yet_another_name() const { return "Again Same Entity"; };
		virtual ~Entity() = 0;  // look for this
		//virtual ~Entity() = default; // either do this, or do above line and provide destructor body(as below)
};
// it is important to have a body for the pure virtual destructor, as
// destructor works in reverse order, and when it reaches to the base class, if
// function body is not provided then what function body will be used for
// destruction of object, that's why we provide a body to it
Entity::~Entity() { std::cout << "from entity\n"; }  // (below is here)

class Player: public Entity {
	private:
		std::string _name;
	public:
		Player(const std::string& name): _name(name) {}
		std::string get_name() const override { return this->_name; }
		// you only have to use those functions only in child which are 'pure virtual'
		// functions
		std::string another_name() const override { return this->_name + " another"; }
		std::string get_class_name() const override { return "Player"; }
		~Player() { std::cout << "from player\n"; }
};

void print_name(const Entity& entity) {
	std::cout << entity.get_name() << std::endl;
	std::cout << entity.another_name() << std::endl;
}

void print_name(const Entity* entity) {
	std::cout << entity->get_name() << std::endl;
	std::cout << entity->another_name() << std::endl;
}

int main(int argc, char **argv) {
	//Entity* e = new Entity();
	//print_name(e);  // you can't allocate an object of abstract class type
	//Even though you have method which is not an abstract one, you can't have object
	//of the abstract class
	Player o{"something"};
	print_name(o);
	Player* p = new Player("someone");
	print_name(p);
	Player* q = new Player("somebody");
	print_name(q);

	delete p;
	delete q;
	return 0;
}