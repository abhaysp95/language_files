/** Questions:
  1. What do you understand by thread and give one example ?
  Ans -> In every application there's a 'default-thread which is main'. We
  create other threads in side of this.

  A thread is known as a lightweight process. Idea is to achieve parallelism
  by dividing a process into multiple threads.
  For example:
  (a) the browser has multiple tabs that can be different threads
  (b) A text editor uses multiple threads
  (c) Editors can use thread to provide features like
  auto-completion(Intellisense) etc.

  Ways to create threads in C++11
  1. Function Pointers
  2. Lambda Functions
  3. Functors
  4. Member functions
  5. Static member functions

*/


// Find the addition of all the odd numbers from 1 to 1900000000 and all the
// even numbers from 1 to 1900000000

#include <iostream>
#include <chrono>
#include <thread>
#include <future>

typedef unsigned long long ull;

void find_odd(ull start, ull end, std::promise<ull>&& res) {
	ull sum{};
	for (ull i = 0; i <= end; ++i)
		if (i & 1)
			sum += i;
	res.set_value(sum);
}

void find_even(ull start, ull end, std::promise<ull>&& res) {
	ull sum{};
	for (ull i = 0; i <= end; ++i)
		if (!(i & 1))
			sum += i;
	res.set_value(sum);
}

int main(int argc, char** argv) {
	ull start = 0, end = 1900000000;

	auto start_time = std::chrono::high_resolution_clock::now();

	std::promise<ull> oddsum, evensum;
	std::future<ull> fos = oddsum.get_future();
	std::future<ull> eos = evensum.get_future();

	std::thread t1(find_odd, start, end, std::move(oddsum));
	std::thread t2(find_even, start, end, std::move(evensum));

	t1.join();
	t2.join();

	//ull oddsum = find_odd(start, end);
	//ull evensum = find_even(start, end);

	auto stop_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<
		std::chrono::microseconds>(stop_time - start_time);

	std::cout << "Odd sum: " << fos.get() << '\n';
	std::cout << "Even sum: " << eos.get() << '\n';

	std::cout << "Time taken: " << (duration.count() / 1e6) << '\n';
}
