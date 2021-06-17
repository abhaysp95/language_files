// main file

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <future>
#include <algorithm>

int main(int argc, char **argv) {
	std::cout << "Main thread id: " << std::this_thread::get_id() << '\n';
	std::vector<std::future<void>> futures;

	for (int i = 0; i < 20; ++i) {
		std::future<void> ftr = std::async(std::launch::async, []() {
					std::this_thread::sleep_for(std::chrono::seconds(1));
					std::cout << std::this_thread::get_id() << ' ';
				});
		// there's no copy constructor for ftr, so we move it
		futures.push_back(std::move(ftr));
	}

	std::for_each(futures.begin(), futures.end(), [](std::future<void>& ftr) {
			ftr.wait();
			});

	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(10));

	return 0;
}