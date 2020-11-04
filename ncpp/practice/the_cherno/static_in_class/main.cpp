#include <iostream>

// static inside a class basically means having only one instance of that
// function/field of class to all the instances of the class

/* now this is going to be same for class or struct, just remember the
 * difference between them told before */

struct Entity {
	//int x, y;
	static int x, y;

	static void print() {
		std::cout << x << ", " << y << std::endl;
	}
};

/* scope and name of variable(you can also initialize here) */
int Entity::x;
int Entity::y;
/* having namespace scope is necessary after making a field static, whether you
 * call through namespace or instance of class */

int main(int argc, char **argv) {
	//Entity e;
	//e.x = 4;
	//e.y = 5;
	Entity::x = 4;
	Entity::y = 5;

	//Entity e1 = {10, 15};  // no longer class member
	//Entity e1;
	//e1.x = 10;  // now there's no point in calling those x and y like this
	//e1.y = 15;

	/* now, x and y are part of Entity class namespace, so */
	Entity::x = 10;
	Entity::y = 15;
	//e.print();
	//e1.print();
	Entity::print();
	Entity::print();

	/* we have to define those static variable or else will get undefine refernce(scope error) */

	/* also, remember static methods can't call or use non-static methods or
	 * fields, so if we make x, y non-static this will break */

	/* every non-static method that you create in class always gets the
	 * instance of current class as a parameter, that's how classes work behind
	 * the scene */
	return 0;
}
