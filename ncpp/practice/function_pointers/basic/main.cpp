#include <iostream>
#include <vector>



using std::cout;
using std::endl;



void printValue(int value) {
	cout << "Value is: " << value << endl;
}



void forEach(const std::vector<int>& values, void(*func)(int)) {
	for (int ele: values) {
		func(ele);
	}
}



int main(int argc, char **argv) {
	std::vector<int> values = {1, 5, 4, 2, 3};
	forEach(values, printValue);

	cout << "Another way" << endl;

	forEach(values, [](int value){ cout << "value: " << value << endl; });  // lambda

	return 0;
}
