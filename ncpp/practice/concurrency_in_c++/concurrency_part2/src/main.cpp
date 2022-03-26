// main file

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

void the_thread(int& i) {
	// problem with passing as reference here, is that, std::thread constructor
	// (which do typechecking for passed argument for the function), has no way
	// to know whether you mean to copy value of i or use it as reference, when
	// you are creating thread. So, i is copied in the thread constructor and
	// when this function wants reference of i, the reference will of the i
	// from the constructor, not from the main function(in this case)
	std::cout << "Hii! I'm thread " << i << '\n';
}

/** if you notice the problem that thread constructor th takes reference of i
 * everytime(it's the same i, only value of i is changing every time, as it is
 * loop), but when this function finishes(after putting the threads to
 * container, I suppose that up to this time some threads may or may not have
 * started executing), i goes out of scope and the when it returns, new value
 * is overwritten to it in the stack and thus wrong values of i is printed now
 * */
void test(std::vector<std::thread>& workers) {
	for (int i = 0; i < 10; ++i) {
		std::thread th(&the_thread, std::ref(i));
		workers.push_back(std::move(th));
		assert(!th.joinable());
		/** a thread is not joinable, if:
		  - it is default constructed
		  - if either of its member join or detach has been called
		  - it has been moved elsewhere
		*/
	}
}

int main(int argc, char **argv) {
	std::vector<std::thread> workers;

	/** but this block (loop) is still not perfect, let's see it by seperating
	 * it to a function

	for (int i = 0; i < 10; ++i) {
		//std::thread th(&the_thread, i);
		std::thread th(&the_thread, std::ref(i));
		// std::ref converts any given variable(object) to reference
		workers.push_back(std::move(th));
		assert(!th.joinable());
	}
	*/

	test(workers);

	std::cout << "Hii! I'm main" << '\n';

	std::for_each(workers.begin(), workers.end(), [](std::thread& th) {
				assert(th.joinable());
				th.join();
			});
	return 0;
}