// main file

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

class BadLengthException: public std::exception {
	private:
		int length;
		using std::exception::what;
	public:
		BadLengthException(int length) { this->length = length; }
		int what() { return this->length; }

		// this function is just for example
		/*const char* what() const throw() {
			std::stringstream ss;
			std::string error;
			ss << this->length;
			error = ss.str();
			return (error.c_str());
		}*/
};


bool checkUsername(std::string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; ++i) {
		if (username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main(int argc, char **argv) {
	int T;
	std::cin >> T;
	while (T--) {
	std::string username;
		std::cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				std::cout << "Valid" << '\n';
			}
			else {
				std::cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			std::cout << "Too short: " << e.what() << '\n';
		}
	}
    return 0;
}