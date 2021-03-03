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

		int operator+(const Point& temp) const {
			int sumOfX = this->_x + temp.getX();
			int sumOfY = this->_y + temp.getY();
			return sumOfX + sumOfY;
		}
};

int main(int argc, char **argv) {
	Point P{10, 20};
	Point Q{30, 40};
	std::cout << "Sum: " << P + Q << std::endl;
	return 0;
}