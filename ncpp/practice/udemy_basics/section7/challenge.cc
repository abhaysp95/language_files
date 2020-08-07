// coding challenge for section7

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector <int> vector1;
	vector <int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);
	cout << "First element of vector1: " << vector1.at(0)
		<< " , second element of vector1: "  << vector1.at(1)
		<< " and it's size is: " << vector1.size() << endl;

	vector2.push_back(100);
	vector2.push_back(200);
	cout << "First element of vector2: " << vector2.at(0)
		<< " , second element of vector2: "  << vector2.at(1)
		<< " and it's size is: " << vector2.size() << endl;

	vector <vector <int>> vector_2d;
	// when we add elements to vector we actually make a copy of what we are inserting (int, float etc.)
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	cout << "\nSize of vector_2d is: " << vector_2d.size() << endl;
	cout << "\nElements of vector_2d are: " << endl;
	cout << vector_2d.at(0).at(0) << endl;
	cout << vector_2d.at(0).at(1) << endl;
	cout << vector_2d.at(1).at(0) << endl;
	cout << vector_2d.at(1).at(1) << endl;

	cout << "\nChangin vector1.at(0) to 1000" << endl;
	vector1.at(0) = 1000;
	cout << "\nChangin vector1.at(0) is: " << vector1.at(0) << endl;

	cout << "\nElements of vector_2d are: " << endl;
	cout << vector_2d.at(0).at(0) << endl;
	cout << vector_2d.at(0).at(1) << endl;
	cout << vector_2d.at(1).at(0) << endl;
	cout << vector_2d.at(1).at(1) << endl;

	cout << "\nFirst element of vector1: " << vector1.at(0)
		<< " , second element of vector1: "  << vector1.at(1)
		<< " and it's size is: " << vector1.size() << endl;

	return 0;
}
