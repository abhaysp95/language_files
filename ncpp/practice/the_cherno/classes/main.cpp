#include <iostream>
#define LOG(x) std::cout << x << std::endl

class Player {
	public:
		int x, y;
		int speed = 5;

	void move(int xa, int ya) {
		/*x += xa;
		y += ya;*/
		this -> x += xa;
		this -> y += ya;
	}
};

/*void move(Player& player, int xa, int ya) {
	LOG(player.x);
	LOG(player.y);
	player.x += xa + player.speed;
	player.y += ya + player.speed;
}*/

int main(int argc, char **argv) {
	Player player;  // instance of Player class
	LOG(player.x);  // some random value, cause not initialized inside class
	player.x = 5;  // if no access modifier is given it's private bydefault in cpp
	LOG(player.x);  // some random value, cause not initialized inside class
	player.y = 13;
	LOG(player.y);
	player.move(2, -3);
	LOG(player.x);
	LOG(player.y);
	return 0;
}
