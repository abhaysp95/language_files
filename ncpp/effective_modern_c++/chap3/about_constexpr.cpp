#include <iostream>
#include <array>

using namespace std;

//int sz;

//constexpr auto arraySize1 = sz;  // will not work

//std::array<int, sz> data1; // same problem

constexpr auto arraySize2 = 10;
std::array<int, arraySize2> data2;

//int sz;
//const auto arraySize = sz;
//std::array<int, arraySize> data;  // error!, arraySize not known at compile time

// C++11, constexpr function may contain no more than single executable statement; a 'return'
//constexpr int pow(int base, int exp) noexcept {
	//return (exp == 0 ? 1 : pow(base, exp - 1));
//}

// In C++14, restriction is loosed
constexpr int pow(int base, int expr) noexcept {
	auto result = 1;
	for(int i = 0; i < expr; ++i) result *= base;
	return result;
}

constexpr auto numConds = 5;
std::array<int, pow(3, numConds)> results;

class Point {
	public:
		constexpr Point(double xVal = 0, double yVal = 0) noexcept:
			x(xVal), y(yVal) {}

		constexpr double xValue() const noexcept { return x; }
		constexpr double yValue() const noexcept { return y; }

		void setX(double newX) noexcept { x = newX; }
		void setY(double newY) noexcept { y = newY; }
	private:
		double x, y;
};

constexpr Point midPoint(const Point& p1, const Point& p2) noexcept {
	return {
		(p1.xValue() + p2.xValue()) / 2,
		(p1.yValue() + p2.yValue()) / 2
	};
}

int main() {
	int base, exp;
	cin >> base >> exp;
	auto baseToExp = pow(base, exp);
	cout << "at runtime from a constexpr function: " << baseToExp << '\n';


	constexpr Point p1(9.4, 27.7);
	constexpr Point p2(28.8, 5.3);

	constexpr auto mid = midPoint(p1, p2);
}
