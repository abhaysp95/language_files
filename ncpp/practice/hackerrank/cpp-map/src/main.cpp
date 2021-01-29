// main file

#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <ios>

int main(int argc, char **argv) {
	size_t queries{}, type{}, val{};
	std::string name{};
	std::cin >> queries;
	std::map<std::string, int> my_map;
	while (queries--) {
		std::cin >> type;
		switch (type) {
			/** to insert and update */
			case 1:
				{
					// whent to use ignore is still a little mystery to me
					//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> name >> val;
					std::map<std::string, int>::iterator pos = my_map.find(name);
					if (pos != my_map.end()) {
						pos->second += val;  // can also use my_map[name] to get value
					}
					else {
						my_map.insert(std::pair<std::string, int>(name, val));
						// my_map[name] = val;  // this will also work
						// since name is not found my_map will create new key with
						// 'name' and give it 'val' value
					}
					break;
				}
			/** to delete */
			case 2:
				std::cin >> name;
				my_map.erase(name);
				break;
			/** to print */
			case 3:
				{
					//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> name;
					std::map<std::string, int>::const_iterator pos = my_map.find(name);
					std::cout << (pos != my_map.end() ? pos->second : 0) << "\n";
					break;
				}
			default:
				break;
		}
	}
	return 0;
}