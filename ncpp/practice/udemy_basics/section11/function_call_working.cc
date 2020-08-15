// function call work on stack and its property LIFO
// every call activation record is pushed when function is called and popped when function is finished
/*   heap
   (free memory)
       |
	   |
	fn call and its variables
	   |
	   |
	main function
*/

#include <iostream>

int func1(int, int);
void func2(int &, int, int);

int func1(int x, int y) {
	int res {};
	res = x + y;
	func2(res, x, y);
	return res;
}

void func2(int &x, int y, int z) {
	x += y + z;
}

int main() {
	int x{10}, y{20};
	int z = func1(x, y);
	std::cout << z << std::endl;
	return 0;
}
