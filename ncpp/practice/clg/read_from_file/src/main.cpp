// main file

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	std::vector<std::string> my_vec;
	std::ifstream file_read_stream;
	file_read_stream.open("this.txt");
	std::string temp_read;
	while (getline(file_read_stream, temp_read)) {
		my_vec.push_back(temp_read);
	}
	size_t count{};
	for (const std::string& str: my_vec) {
		std::cout << count++ << ": " << str << "\n";
	}
	std::cout << std::endl;
	return 0;
}