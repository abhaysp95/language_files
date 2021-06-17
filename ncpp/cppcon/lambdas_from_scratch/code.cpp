#include <iostream>
#include <cassert>

class Plus {
	private:
		int value;
	public:
		Plus(int v): value(v) {}
		int operator()(int x) const { return x + value; }
};

template<typename T> struct TD;

int main() {
	/*auto plus = Plus(1);
	assert(plus(42) == 43);*/

	// but all the above code is boilerplate of what we actually we want
	// we want value and something (int x) and return x + value;, that's it

	/** lambda reduce boilerplate */

	auto plus = [value = 1](int x) { return x + value; };
	/** this is still an obbject of class type that is assigned to variable 'plus', but compiler is gonna pick a name for it */
	assert(plus(42) == 43);
	// TD<decltype(x)> td;  // <-- for plus this gives TD(<lambda at 'file,line,col'>)
}

