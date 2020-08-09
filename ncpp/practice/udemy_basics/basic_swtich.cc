// demonstration of basic swtich statement

#include <iostream>

using std::cout;
using std::endl;

enum Colors {
	red = 196,
	green = 82,
	blue = 17,
};

int main() {
	Colors selected_colors {red};
	switch (selected_colors) {
		case red:
			cout << "RED!" << endl;
			break;
		case green:
			cout << "GREEN!" << endl;
			break;
		case blue:
			cout << "BLUE!" << endl;
			break;
		default:
			cout << "Wrong Choice!" << endl;
	}
	return 0;
}
