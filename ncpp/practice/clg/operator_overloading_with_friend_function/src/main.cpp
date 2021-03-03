// main file

#include <iostream>

class Point {
	private:
		int _x{};
		int _y{};
	public:
		Point() {}
		Point(int x, int y): _x{x}, _y{y} {}

		void setX(int x) { this->_x = x; }
		void setY(int y) { this->_y = y; }

		int getX() const { return this->_x; }
		int getY() const { return this->_y; }

		friend int operator+(const Point& p, const Point& q);
};

int operator+(const Point& p, const Point& q) {
	Point r{p._x + q.getX(), p._y + q.getY()};
	return r.getX() + r.getY();
}

int main(int argc, char **argv) {
	Point P{10, 20};
	Point Q{30, 40};
	std::cout << "Sum: " << (P + Q) << std::endl;
	return 0;
}