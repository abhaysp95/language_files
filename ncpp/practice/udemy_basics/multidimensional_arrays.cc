// using multidimensional arrays in C++

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	const unsigned int row {2};  // reviewers
	const unsigned int column {3};  // movies
	unsigned int movie_review [row][column] {
		{4, 3, 8},
		{3, 5, 6}
	};

	cout << "Rating for 2nd movie by 1st reviewer: " << movie_review [0][1] << endl;
	cout << "Rating for 3rd movie by 2nd reviewer: " << movie_review [1][2] << endl;

	// you can also take the entry in same way

	cout << "1st reviewer changes the rating for 2nd film: " << endl;
	cout << "Enter the new rating> ";
	cin >> movie_review [0][1];

	cout << "2nd reviewer changes the rating for 3rd film: " << endl;
	cout << "Enter the new rating> ";
	cin >> movie_review [1][2];

	cout << "\nNew ratings are: " << endl;
	cout << "Rating for 2nd movie by 1st reviewer: " << movie_review [0][1] << endl;
	cout << "Rating for 3rd movie by 2nd reviewer: " << movie_review [1][2] << endl;

	return 0;
}
