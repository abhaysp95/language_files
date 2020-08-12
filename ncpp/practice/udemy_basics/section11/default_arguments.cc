// get the fruit list

#include <iostream>

// void print_fruits(int, int, int);  only when function body is above the body of the another function where it is called, else
void print_fruits(int apples=3, int oranges=7, int mangos=13);

int main() {
	int apples{}, oranges{}, mangos{};

	print_fruits();
	print_fruits(5);
	print_fruits(7, 11);
}

// if we defining default argument in function definition and not in
// function prototype then the function must be defined before function
// call
// void print_fruits(int apples=3, int oranges=7, int mangos=13) {
void print_fruits(int apples, int oranges, int mangos) {
	std::cout << "Today bought:" << std::endl;
	std::cout << apples << " apples, " << oranges << " oranges, " << mangos << " mangos." << std::endl;
}
