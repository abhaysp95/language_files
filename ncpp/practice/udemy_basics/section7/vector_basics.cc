// demonstration of vector in C++

#include <iostream>
#include <vector>

//using std::cout;
//using std::endl;
//using std::vector;

using namespace std;

int main() {

	// vectors are object-oriented template class, so we must provide its type
	vector <char> vowels;

	// empty vector with no element
	vector <int> test_scores;

	// constructor initiallization, containing 5 chars, not giving a initializer list
	vector <char> consonant (15);

	// these 10 test_scores1 element will automatically be initialized with 0, unlike array
	vector <int> test_scores1 (10);

	// with initializer list
	vector <char> vowels1 {'a', 'e', 'i', 'o', 'u'};
	// character literal will have single quote, not double

	// size of vector with initializer
	vector <double> hi_temperatures (365, 80.0);
	// this will initialize all 365 elements with 80.0

	// first will be 80.0 and rest 81.0
	// vector <double> hi_temperatures1 (365, 80.0, 81.0);, this is wrong as, it takes only 2 args

	// accessing vector element(subscripting) could be done by [] just like array

	// vectors also provide no bound checking with [], but provides useful function for checking

	// when we create a vector we really are creating a object, so there's at() method also

	cout << "First of hi_temperatures1: " << hi_temperatures[0] << endl;
	cout << "Second of hi_temperatures1: " << hi_temperatures.at(1) << endl;

	return 0;

}
