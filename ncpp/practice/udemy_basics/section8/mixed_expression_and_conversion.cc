// conversion of the variable of one data type into another

#include <iostream>

using namespace std;

int main() {
	const unsigned short count {3};
	int var1{}, var2{}, var3{};

	cout << "Enter the three integers: " << endl;
	cin >> var1 >> var2 >> var3;

	int total = var1 + var2 + var3;
	double average {};

	average = static_cast<double>(total) / count;
	cout << "Average of the entered number is: " << average << endl;
	return 0;
}

/* Type casting in C++
 * When casting a lower data to higher data type(which is done automatically,
 * if not explicitly done, as lower type value will easily fit inside upper
 * data type variable) is known as "Promotion"
 * While, doing it's reverse means changing from upper to lower means wrapping
 * a value is known as "Demotion" and many times compiler warns about it
 * In line 17, variable 'total' is explicitly casted to double data type, since
 * it was wrapping the float value as int
 * the "static_cast" double checks if the variable can be converted to double,
 * while (double)total is old(C style) casting technique
 */
