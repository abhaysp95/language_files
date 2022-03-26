// main file

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
	std::vector<std::thread> workers;
	for (int i = 0; i < 10; ++i)
		workers.push_back(std::thread([i]() {
					std::cout << "Hii, I'm worker " << i << '\n';
					}));

	/*for (int i = 0; i < 10; ++i)
		workers.push_back(std::thread([](int& i) {
					std::cout << "Hii, I'm worker " << i << '\n';
					}, i));*/

	std::cout << "Hii from main!!!" << '\n';
	std::for_each(workers.begin(), workers.end(), [](std::thread& th) {
			th.join();
			});
	return 0;
}