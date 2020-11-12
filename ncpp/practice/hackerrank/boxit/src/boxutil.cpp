#include "../inc/boxutil.hpp"
#include "../inc/getbox.hpp"
#include <iostream>

void checkBox() {
	int n;
	std::cin >> n;
	test::Box temp;
	for (int i = 0; i < n; ++i) {
		int type;
		std::cin >> type;
		if (type == 1) {
			std::cout << temp << std::endl;
		}
		if (type == 2) {
			int l, b, h;
			std::cin >> l >> b >> h;
			test::Box NewBox(l, b, h);
			temp = NewBox;
			std::cout << temp << std::endl;
		}
		if (type == 3) {
			int l, b, h;
			std::cin >> b >> h;
			test::Box NewBox(l, b, h);
			if (NewBox < temp) {
				std::cout << "Lesser\n";
			}
			else  {
				std::cout << "Greater\n";
			}
		}
		if (type == 4) {
			std::cout << temp.CalculateVolume() << std::endl;
		}
		if (type == 5) {
			test::Box NewBox(temp);
			std::cout << NewBox << std::endl;
		}
	}
}
