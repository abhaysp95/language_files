#include <iostream>
#include <string>

int main(int argc, char **argv) {
	std::string str1, str2;
	std::cin >> str1 >> str2;
	std::cout << str1.size() << " " << str2.size() << std::endl;
	std::cout << str1 << str2 << std::endl;
	std::string temp;
	temp = str1.at(0);
	str1 = str1.replace(0, 1, str2, 0, 1);
	str2 = str2.replace(0, 1, temp);
	std::cout << str1 << " " << str2 << std::endl;
	return 0;
}
