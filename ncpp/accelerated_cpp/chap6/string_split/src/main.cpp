// main file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> vec_str;
typedef std::string::const_iterator str_const_iter;
typedef std::vector<std::string>::const_iterator vec_str_const_iter;

vec_str split( const std::string& got_str );
void print_iter( const vec_str& vec );
void print_new_for( const vec_str& vec );

int main(int argc, char **argv) {
	std::string mystr;
	std::cout << "Enter a string: " << std::endl;
	getline( std::cin, mystr );
	vec_str splits = split( mystr );
	/** different ways to print */
	print_iter( splits );
	std::cout << "----------------" << std::endl;
	print_new_for( splits );
	return 0;
}

// we need to use these custom functions because isspace is overloaded, and it's
// not easy to pass an overloaded function as argument to a template function(find_if)
// cause compiler will not know which version of overloaded function we mean
bool is_space( const char& c ) {
	return isspace(c);
}

bool is_not_space( const char& c ) {
	return !isspace(c);
}

vec_str split( const std::string& got_str ) {
	vec_str return_splits;
	str_const_iter iter;
	iter = got_str.begin();

	// library functions are written to gracefully handle the calls that pass an
	// empty range, at some point, the first call to find_if() will set iter to value
	// returned by got_str.end() but there's no need to check before passing iter
	// to second call of find_if(), reason being that find_if will look in the empty
	// range ( iter, got_str.end() ) and will return got_str.end() element to indicate
	// that there's no matched element
	while (iter != got_str.end()) {
		// find_if calls predicate on each element in sequence(uses first iter args),
		// stopping when it finds an element for which the predicate yields true
		iter = std::find_if( iter, got_str.end(), is_not_space );
		// if find_if fails to find the element for which predicate yields true,
		// it'll yield second argument
		str_const_iter sec_iter = std::find_if( iter, got_str.end(), is_space );
		if (iter != got_str.end()) {
			return_splits.push_back( std::string( iter, sec_iter ) );
		}
		iter = sec_iter;
	}
	return return_splits;
}

void print_iter( const vec_str& vec ) {
	vec_str_const_iter iter = vec.begin();
	while (iter != vec.end()) {
		// *iter++ means *(iter++)
		// or *iter then ++iter
		std::cout << *iter++ << "\n";
	}
	std::cout << std::endl;
}

void print_new_for( const vec_str& vec ) {
	for (const std::string& str: vec) {
		std::cout << str << "\n";
	}
	std::cout << std::endl;
}