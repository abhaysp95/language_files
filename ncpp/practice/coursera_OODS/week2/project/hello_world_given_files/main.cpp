/*
 * @file main.cp
 * University of Illinoi
 * Object-Oriented Data Structures in C++ - Week
 * Hello World Projec

 * @author Eric Huber - University of Illinois staff - July 201
**/
// You need to include some header(s) here

#include <iostream>

// You need to define your main() function here

int main(int argc, char **argv) {
	std::cout << "Hello, world\nGreetings from Illinois" << std::endl;
	return 0;
}

// Notes
// If you get a compiler error saying "undefined reference to main"
// it means you haven't defined your main function correctly
// Standard output is the system stream for normal text output on the terminal
// One way to write to it, that you have learned, is with std::cout
// Your main function should write the following messages to standard output
// Hello, world
// Greetings from Illinois
// Also note, the autograder does not care about letter case, punctuation
// or spacing! But it does care about spelling and the order of words

