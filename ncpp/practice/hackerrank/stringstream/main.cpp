#include<iostream>
#include<vector>
#include<sstream>

std::vector<int>* parseInt(std::string& str) {
	std::cout << "Got line: " << str << std::endl;
	std::stringstream ss;
	ss << str;
	std::vector<int> *temp = new std::vector<int>();
	std::cout << "up here" << std::endl;
	while (true) {
		int value;
		char comma;
		if (ss >> value) {
			temp->push_back(value);
			ss >> comma;
		}
		else {
			break;
		}
	}
	std::cout << "Got line: " << str << std::endl;
	return temp;
}

std::vector<int>* parseInt1(std::string& str) {
	std::stringstream ss;
	ss << str;
	std::vector<int> *temp = new std::vector<int>();
	int value;
	while (ss >> value) {  // ss will return true if it can extract at that moment
		temp->push_back(value);
		if (ss.peek() == ',') {
			ss.ignore();
		}
	}
	return temp;
}

int main(int argc, char **argv) {
	std::string str;
	std::getline(std::cin, str);
	std::vector<int> *integers = parseInt(str);
	std::vector<int> *integers1 = parseInt1(str);
	for (int i = 0; i < integers->size(); ++i) {
		std::cout << integers->at(i) << std::endl;
	}

	for (int i = 0; i < integers1->size(); ++i) {
		std::cout << integers1->at(i) << std::endl;
	}
	return 0;
}
