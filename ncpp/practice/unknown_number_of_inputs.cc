// print total of numbers entered at runtime without knowing the range

#include <iostream>

int main() {
	int sum = 0, value = 0;
	std::cout << "reads until EOF(press <C-d> after pressing <CR>)" << std::endl;
	std::cout << "Sum at runtime" << std::endl;
	while ( std::cin >> value ) {
		sum += value;
	}
	std::cout << "Sum is " << sum << std::endl;
	return 0;
}


/* line 9: expression reads the next number from the stdin and stores that
 number in 'value'. The input operator returns its left operand, which in
 this case is std::cin. This condition, therefore, tests std::cin.

 When we use an istream as a condition, the effect is to test the state of the
 stream. If the stream is valid—that is, if the stream hasn’t encountered an
 error—then the test succeeds. An istream becomes invalid when we hit
 end-of-file or encounter an invalid input, such as reading a value that is not
 an integer. An istream that is in an invalid state will cause the condition to
 yield false. */
