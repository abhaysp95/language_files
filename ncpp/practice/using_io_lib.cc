// demonstration basic usage of io lib

/* iostream = istream and ostream
some main objects
istream = cin
ostream = cout, cerr, clog */

#include <iostream>

int main() {
	std::cout << "Enter two numbers: " << std::endl;
	// The result of the output operator is its left-hand operator
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << std::endl;
	return 0;
}

/* line 11: second operator prints 'endl', which is special value called
   'manipulator'.
   wrting endl has the effect of ending the current line and flushing the
   buffer associated with that device
   Flushing the buffer ensures that all the output the program has generated
   so far is actually written to the output stream, rather than sitting
   in memory waiting to be written

   The prefix  indicates that names cout and endl are defined inside
   the namespace std.
   Namespace allow us to avoid the inadvertent collisions between the
   names we define and uses of those same names inside a library.
   Writing cout uses the scope operator(::) to say that we want to use
   the name cout that is defined in the namespace std
   So, if we don't give 'using namespace std' and also we don't write std::cout,
   but write only cout, the error will be 'cout was not declared in this scope.'

   The input operator(>>) behaves analogously to the output operator(<<)
   It takes an istream as its left-hand operand and an object as its
   right-hand operand
   Like the output operator, the input operator returns its left-hand
   operator as its result.
*/
