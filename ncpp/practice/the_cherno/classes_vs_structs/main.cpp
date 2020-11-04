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

/** class fields are private by-default and struct are public, however we can
 * explicitly tell them to be private, just like we do public in class */

/** struct in C++ exist due to compatibility reason with C, you can have also
#define struct class, and it'll make all struct behave like class */


struct Villian {
	//private:
	int x, y;
	int speed = 5;

	void move(int xa, int ya) {
		/*x += xa;
		y += ya;*/
		this -> x += xa;
		this -> y += ya;
	}
};


/** you can have struct where you don't want to have bunch of methods doing
 * different things, a small example of struct could be having a few field
 * variable and just changing them */

struct vec2 {
	float x, y;

	void add(const vec2& other) {
		x += other.x;
		y += other.y;
	}
}

/** so, struct should just be structure of data */


/*void move(Player& player, int xa, int ya) {
	LOG(player.x);
	LOG(player.y);
	player.x += xa + player.speed;
	player.y += ya + player.speed;
}*/

int main(int argc, char **argv) {
	Player player;  // instance of Player class
	LOG("Player:");
	LOG(player.x);  // some random value, cause not initialized inside class
	player.x = 5;  // if no access modifier is given it's private bydefault in cpp
	LOG(player.x);  // some random value, cause not initialized inside class
	player.y = 13;
	LOG(player.y);
	player.move(2, -3);
	LOG(player.x);
	LOG(player.y);
	Villian villian;
	villian.x = 10;
	villian.y = 6;
	LOG("Villian:");
	LOG(villian.x);
	LOG(villian.y);
	villian.move(4, 6);
	LOG(villian.x);
	LOG(villian.y);
	return 0;
}
