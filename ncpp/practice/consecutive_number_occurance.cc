// give occurance of numbers entered

#include <iostream>

int main() {
	int curval = 0, value = 0;
	// read first value, so that we have data to process
	if (std::cin >> curval) {
		// std::cout << "Entered curval in if " << curval << std::endl;
		int cnt = 1;
		while (std::cin >> value) {
			//std::cout << "Entered value in while " << value << std::endl;
			if (value == curval) {
				++cnt;
			}
			else {
				std::cout << curval << " occurs " << cnt << " times." << std::endl;
				curval = value;
				cnt = 1;
			}
		}
		//std::cout << 3 << std::endl;
		// this line will be printed when you press for EOF, as stdin is still
		// open for input
		std::cout << curval << " occurs " << cnt << " times." << std::endl;
	}
	return 0;
}
