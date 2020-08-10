// build a alphbet cipher

#include <iostream>
#include <cctype>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string alphabets_inserial {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string alphabets_cipher {"DrCAGHIJKstuLMNEFjRnopWXqPQlmiBSTvOwxyfghcdeYZkzabUV"};

	string user_message {};
	string cipher_message {};
	getline(cin, user_message);

	// ciphering the message

	for (char c: user_message) {
		// or we can just find position in alphabets_inserial if existed by:
		// size_t position = alphabets_inserial.find(c);
		// if(position == string::npos) { cipher_message += c; }
		// rest you know what to do
		if (!isalpha(c)) {
			cipher_message += c;
			continue;
		}
		size_t index = alphabets_inserial.find(c);
		char ciphered_char = alphabets_cipher.at(index);
		cipher_message += ciphered_char;
	}

	cout << "--------------------------------" << endl;
	cout << "Ciphering the message..." << endl;
	cout << "--------------------------------" << endl;
	cout << "User message: " << user_message << endl;
	cout << "Ciphered Message: " << cipher_message << endl;
	cout << "--------------------------------" << endl;

	string decipher_message {};
	for (char c: cipher_message) {
		if (!isalpha(c)) {
			decipher_message += c;
			continue;
		}
		size_t index = alphabets_cipher.find(c);
		char normal_char = alphabets_inserial.at(index);
		decipher_message += normal_char;
	}

	cout << "\n" << endl;
	cout << "--------------------------------" << endl;
	cout << "Deciphering the same message..." << endl;
	cout << "--------------------------------" << endl;
	cout << "Ciphered Message: " << cipher_message << endl;
	cout << "Deciphered message: " << decipher_message << endl;
	cout << "--------------------------------" << endl;

	return 0;
}
