// main file

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	/** both the definitions are valid */
	const std::string hello = "Hello";
	const std::string message = hello + ", world" + "!";
	const std::string exclam = "!";
	//const std::string message1 = "Hello" + ", world" + exclam;  // invalid
	/** both scope valid */
	{
		const std::string s = "a string";
		std::cout << s << std::endl;
	}
	{
		const std::string s = "another string";
		std::cout << s << std::endl;
	}
	{
		const std::string s = "a string";
		std::cout << s << std::endl;
		{
			const std::string s = "another string";
			std::cout << s << std::endl;
		}
	}
	{
		std::string s = "a string";
		{
			std::string x = s + ", really";
			std::cout << s << std::endl;
			std::cout << x << std::endl;
		}
	}
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
		<< std::endl << "And what is yours?";
	std::cin >> name;
	std::cout << "Hello, " << name
		<< "; nice to meet you too" << std::endl;
	return 0;
}