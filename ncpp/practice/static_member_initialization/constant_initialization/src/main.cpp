// main file

#include <iostream>


// constant initialization(compile-time)

struct MyStruct {
	static int a;
};

int MyStruct::a = 67;  // const-initializated because 67 is compile time constant

// forced const-initialization
// treat the variable as constant expression and perform their evaluation and
// initialization at compile time
struct Point {
	float x{};
	float y{};
};

constexpr Point myPoint(Point point, float x_value, float y_value) {
	return {point.x + x_value, point.y + y_value};
}

// OK const-initialized, enforced by compiler
constexpr auto p2 = myPoint({3.f, 4.f}, 1.f, -1.f);

// still const-initialized, but not enforced by compiler
auto p1 = p2;

struct Line {
	Line(Point x, Point y) {}
};

// compile error(constexpr variable can't have non-literal type 'const line')
// in other words, l can't be const initialized(cause no constexpr constructor present)
// make the Line(...) {} constructor constexpr(probably one of the solutions)
//constexpr Line l({3.4f, 4.5f}, {-1.2f, 6.3f});


// there's also "constinit(c++20)" which can be considered second line of
// defence here, the difference between constexpr and constinit is constexpr
// have the expression(variable) in immutable state while constinit have it in
// mutable state, both are same in working of making the expression evaluate
// and initialize at compile time

int main(int argc, char **argv) {
	std::cout << MyStruct::a << std::endl;
	return 0;
}