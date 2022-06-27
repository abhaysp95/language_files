// throwing exceptions in nested try blocks

#include <iostream>

void throwIt(int i) {
	throw i;  // throws the parameter value
}

int main(void) {
	for (int i = 0; i <= 5; i++) {
		try {
			std::cout << "outer try:\n";
			if (i == 0) {
				throw i;
			}
			if (i == 1) {
				throwIt(i);
			}

			try {
				std::cout << "inner try:\n";
				if (i == 2) {
					throw static_cast<long>(i);
				}
				if (i == 3) {
					throwIt(i);
				}
			} catch (int n) {
				std::cout << "catch int for inner try. " << "Exception " << n << std::endl;
			}

			std::cout << "outer try:\n";
			if (i == 4) {
				throw i;
			}
			throwIt(i);
		} catch (int n) {
			std::cout << "catch int for outer try. " << "Exception " << n << std::endl;
		} catch (long n) {
			std::cout << "catch long for outer try. " << "Exception " << n << std::endl;
		}
	}
}
