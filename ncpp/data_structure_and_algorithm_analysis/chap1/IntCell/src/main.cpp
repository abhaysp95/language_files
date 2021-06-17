// main file

#include <iostream>
#include "../inc/IntCellUtil.hpp"

using namespace std;

int main(int argc, char **argv) {
	IntCell m;
	m.write(5);
	cout << m.read() << endl;

	m = new IntCell;  // this heap instance of IntCell is already freed inside constructor
	m.write(10);
	cout << m.read() << endl;
	return 0;
}