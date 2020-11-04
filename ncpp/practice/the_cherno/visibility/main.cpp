#include <iostream>

class Entity {
	int x;  // this is private, c++ doesn't have any default
	protected:
		int y;
		void print() {}  // only child class can access this
	public:  // all accessible
		Entity() {
			x = 0, y = 0;
			print();
		}
};

class Player: public Entity {
	public:
		Player() {
			y = 10;
			print();
		}
};

int main(int argc, char **argv) {
	Entity e;
	//e.x;  // can't do it
	//e.print();  can't do that
	Player p;
	return 0;
}
