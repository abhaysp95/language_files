// a basic ternary operation

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	short num1{}, num2{};
	cin >> num1 >> num2;

	if (num1 != num2) {
		cout << "Largest: " <<  (num1 > num2 ? num1 : num2) << endl;
		cout << "Smallest: " <<  (num1 > num2 ? num2 : num1) << endl;
	}
	else {
		cout << "Both numbers are same" << endl;
	}

	// find out how to use variables inside ternary operation with cout/output redirection operator
	//cout << (num1 == num2
			//? "Both are same"
			//: (num1 > num2)
				//? "Largest1: " << num1
				//: "Largest2: " << num2) << endl;
	return 0;
}

/* in ternary operation (exp1 ? exp2 : exp3) make sure that exp2 and exp3 return same type for best practice, or must be convertible to some common type */
