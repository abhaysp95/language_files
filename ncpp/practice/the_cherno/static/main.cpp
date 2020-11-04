#include <iostream>

//int s_variable = 10;
extern int s_variable;  // unless, static.cpp doesn't have any variable with s_variable name which is not static this will give error, so lets do that

void function() {

}

int main(int argc, char **argv) {
	int s_variable = 15;  // this is local, so using static inside a function will not affect the static one outside the function, we use them as static as they prevent the nome collision in linking with different files */
	std::cout << s_variable << std::endl;
	return 0;
}
