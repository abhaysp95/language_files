#include <iostream>

class Entity {
	public:
		float x, y;

		void move(int xa, int ya) {
			x += xa;
			y += ya;
		}
};

class Player : public Entity {
	public:
		const char* name;

		void printName() {
			std::cout << name << std::endl;
		}
};

int main(int argc, char **argv) {
	Player player;
	player.x = 10;
	player.y = 15;
	player.move(5, 10);
	player.name = "New Player";
	player.printName();
	std::cout << sizeof(Entity) << std::endl;  // 8
	std::cout << sizeof(Player) << std::endl;  // 16, extra 8 is size of the pointer name
	return 0;
}
