#include <iostream>
#include <cstring>
#include <string>

#include <stdlib.h>

int main(int argc, char **argv) {
	const char* name = "this\0string";  // string literals are stored in the read-only section of the memory(const data segment), so it's better to have it const
	//name[2] = 'a';  // not possible(or maybe, it depends)
	// however,
	char name1[8] = "this\0is";
	name1[3] = 'a';  // this works because it basically copies the address to another register and then change the newly one created and then load this new one back to the register of old one
	std::cout << strlen(name) << std::endl;
	std::cout << name1 << std::endl;

	const char* name2 = u8"string";
	const wchar_t* name3 = L"string";  // maybe 2 or 4
	const char16_t* name4 = u"string";  // 2
	const char32_t* name5 = U"string";  // 4

	using namespace std::string_literals;  // c++14
	std::string name6 = "string";
	std::string name7 = static_cast<std::string>("string") + static_cast<std::string>("anotherstring");
	// type casting is necessary cause "string" is just a string literal(array of char, or pointer)
	std::cout << name7 << std::endl;
	// another way using string_literals
	std::wstring name8 = L"string"s + L" anotherstring";
	std::u32string name9 = U"string"s + U" anotherstring";
	std::cout << name6 << std::endl;
	std::cout << name7 << std::endl;
	std::cout << name8 << std::endl;
	std::cout << name9 << std::endl;

	const char* multiLine = R"(Line1
	Line2
	Line3)";
	// is equal to
	const char* multiLine1 = "Line1\n"
	"line2\n"
	"line3\n";
	return 0;
}
