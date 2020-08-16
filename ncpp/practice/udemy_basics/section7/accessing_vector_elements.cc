#include <iostream>
#include <vector>

int main() {
	std::vector <int> even {0, 2, 4, 6};  // size 4
	std::vector <double> temp (20, 4.5);  // size 3

	std::cout << "Second element of even: " << even[1] << std::endl;
	std::cout << "First element of temp: " << temp.at(0) << std::endl;
	std::cout << "Third element of temp: " << temp.at(2) << std::endl;
	std::cout << "Fourth element of temp: " << temp.at(3) << std::endl;

	for (int &num: even) {  // change the value
		num = 20;
	}
	std::cout << "Second element of even: " << even[1] << std::endl;

	temp.push_back(10.3);  // appends the element
	std::cout << "Second element of temp: " << temp.at(1) << std::endl;
	std::cout << "21st element of temp: " << temp.at(20) << std::endl;

	std::cout << "temp vector have size of " << temp.size() << std::endl;

	// take some inputs from user
	std::cout << "Provide some input for temp" << std::endl;
	double x {0};  // vector should have same data type
	std::cin >> x;
	temp.push_back(x);  // appends the element
	std::cin >> x;
	temp.push_back(x);  // appends the element
	std::cout << "temp vector have size of " << temp.size() << std::endl;

	// changing and element from previous
	std::cout << "Tenth element of vector temp: " << temp.at(9) << std::endl;
	std::cout << "Enter new value: " << std::endl;
	std::cin >> temp.at(9);
	std::cout << "Now, Tenth element of vector temp: " << temp.at(9) << std::endl;

	std::cout << "Let's see two dimensional vector" << std::endl;

	std::vector <std::vector <int>> movie_rating {
		{1, 3, 5, 7},
		{2, 4, 6, 8},
		{0, 2, 5, 10}
	};

	std::cout << "Second element of first row of vector movie_rating " << movie_rating.at(0).at(1) << std::endl;

	return 0;
}
