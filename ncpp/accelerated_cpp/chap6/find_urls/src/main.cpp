// main file

#include <iostream>
#include "../inc/find_urls_util.hpp"  /** vector and string header are in here */

#include <fstream>

int main(int argc, char **argv) {
	vec_str got_urls_vec;  // a string can contain multiple urls
	vec_str temp_vec;
	const std::string input_file = "input_urls.txt";
	std::ifstream input_file_stream;
	input_file_stream.open(input_file);
	std::string get_lines;
	while (getline(input_file_stream, get_lines)) {
		temp_vec = find_urls(get_lines);
		for (const std::string& url: temp_vec) {
			got_urls_vec.push_back(url);
		}
		temp_vec.erase(temp_vec.begin(), temp_vec.end());
	}
	std::cout << "/**   URLs in input file " << input_file << "   */ \n";
	for (const std::string& url: got_urls_vec) {
		std::cout << url << "\n";
	}
	std::cout << std::endl;
	return 0;
}