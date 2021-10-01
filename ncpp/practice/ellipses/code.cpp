#include <iostream>
#include <cstdarg>
#include <cstring>

void func(int i, ...) {
	va_list start;
	int list;

	va_start(start, i);  // initializes start with information to access the value present after i
	while((list = va_arg(start, int)) != 0) {
		std::cout << list << '\n';
	}
	va_end(start);  // ends the value of va_list
}

/** if the arguments type vary, we must know their types too */
void func2(int i, ...) {
	va_list start;
	va_start(start, i);

	//std::string st = va_arg(start, char*);
	char* st = va_arg(start, char*);
	double d = va_arg(start, double);
	int ii = va_arg(start, int);
	int ch = va_arg(start, int);  // this is because, char will be promoted to int

	char buf[1024];
	snprintf(buf, (strlen(st) + 14), "%s, %lg, %d, %c", st, d, ii, ch);
	std::cout << buf << std::endl;
}

/** you can already see what the problems are in func2, also we also don't know
 * the number of arguments passed. A direct approach would be to pass the
 * number of arguments as threshold value */
void largest(int i, ...) {  // in this way, the arguments present in ellipses can be of different type
	va_list start;
	decltype(i) value{}, next{};

	va_start(start, i);
	value = va_arg(start, decltype(i));
	for(int ii = 0; ii < i; ii++) {
		next = va_arg(start, decltype(i));
		if(next > value) value = next;
	}
	std::cout << "Largest value: " << value << std::endl;
}

/** ellipses overloading */
void type_check(char c, ...) {}
void type_check(char c, int i, ...) {}
void type_check(...) {}

int main(int argc, char** argv) {
	func(2, 23, 435, 9000);  // 2 isn't in va_list(it's in i)
	func2(3, "not so good", 3.14, 10, 'c');
	largest(5, 6, 3, 1, 9, 5);
	type_check('M', 10, "this should call second");
	type_check('N', 10.243, "this should call second");  // implicit conversion of double to int
	type_check('O', 'P', "this will call first");
	type_check("string", "this will call third");
}
