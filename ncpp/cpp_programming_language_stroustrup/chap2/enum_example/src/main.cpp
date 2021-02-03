// main file

#include <iostream>

// starts from 0
enum class Color { red, green, blue };
enum class Traffic_light { red = 1, yellow = 2, green = 3 };

Traffic_light& operator++(Traffic_light& t) {
	// prefix increment++
	switch (t) {
		case Traffic_light::green:
			return t = Traffic_light::red;
		case Traffic_light::yellow:
			return t = Traffic_light::green;
		case Traffic_light::red:
			return t = Traffic_light::yellow;
	}
}

int main(int argc, char **argv) {
	Color col = Color::red;
	std::cout << "col: " << (int)col << std::endl;
	Traffic_light light = Traffic_light::red;
	std::cout << "light: " << (int)light << ", next: " << (int)++light << std::endl;
	return 0;
}