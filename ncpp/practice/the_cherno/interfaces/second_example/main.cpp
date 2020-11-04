#include <iostream>
#include <string>

/* Printable behaves like interface but it's just a class actually */
class Printable {
	public:
		virtual std::string getClassName() = 0;  // abstract method
};

class Entity : public Printable {
	private:
		int m_Id = 0;
	public:
		virtual std::string getName() { return "New Entity"; }
		virtual int getSize() { return sizeof(this); }
		virtual int getId() { return m_Id; }
		std::string getClassName() override { return "Entity Class"; }
};

// you don't need to actually inherit Printable explicitly since Entity is
// already inheriting Printable, it'll just create ambiguity, however you can
// have multiple inheritance seperated by ,
class Player: public Entity {
	private:
		const char* m_Name = "Player";
		int m_Id;
	public:
		Player(const char* name, int id)
			: m_Name(name), m_Id(id) {}

		std::string getName() override { return m_Name; }
		int getId() override { return m_Id; }
		std::string getClassName() override { return m_Name; }
};

void printClass(Printable* obj) {
	std::cout << "Class: " << obj -> getClassName() << std::endl;
}

void printName(Entity* e) {
	std::cout << "Name: " <<  e -> getName() << std::endl;
}

void printId(Entity* e) {
	std::cout << "Id: " <<  e -> getId() << std::endl;
}

void printSize(Entity* e) {
	std::cout << "Size: " << e -> getSize() << std::endl;
}

int main(int argc, char **argv) {
	Entity* e = new Entity();
	printName(e);
	printSize(e);
	printId(e);
	printClass(e);
	Player* p = new Player("New Player", 10);
	printName(p);
	printSize(p);
	printId(p);
	printClass(p);
	return 0;
}
