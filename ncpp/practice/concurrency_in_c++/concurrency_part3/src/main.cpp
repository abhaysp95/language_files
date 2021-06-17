// main file


// topic focus: sharing data between threads

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>
#include <list>
#include <cmath>
#include <chrono>




/**             third phase             */

void to_sin(std::list<double>&& list) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::for_each(list.begin(), list.end(), [](double& x) {
				x = sin(x);
			});
}

int main() {
	std::list<double> lst;
	const double pi = 3.141592;
	const double epsilon = 0.000001;

	for (double i = 0.0; i < 2 * pi + epsilon; i += pi / 16)
		lst.push_back(i);

	/** As you might have noticed, there isn't a real con-currency here */
	std::thread th(to_sin, std::move(lst));

	// this were to just check that, the thread above started executing and it
	// worked in a single time without being preempted, that's why I got 1000
	// everytime in last ( I suppose )

	// there's a 'self imposed ban' for accessing the data structure in time
	// duration here between of creation of thread and thread join

	// this little experiment was done before introducing sleep in the 'th' thread
	//lst.push_back(100);
	//std::cout << "done\n";

	std::for_each(lst.begin(), lst.end(), [](double& x) {
				int&& count = static_cast<int>(10 * x + 10.5);
				for (int i = 0; i < count; ++i)
					std::cout << '*';
				std::cout << '\n';
			});

	th.join();
	/** So, basic principle here is that, threads have to communicate and take
	 * turns to acess shared data structure, these points of communication are
	 * called synchronization points, there are 4 such synchronization points
	 * in this program, 'thread creation', 'thread join', 'begining of thread
	 * function', 'end of thread function' (this probably means that these 2
	 * thread communication 2 times with each other) */

	/** there's a 'happen before' relation, that is, the thread creation
	 * happens before the start of thread function and the end of thread
	 * function happens before thread join */


	/** let's create a race condition, I'm going to put this for_each block
	 * between the 'self imposed ban' time duration of 'th' thread and
	 * introduce sleep to it */

	/*std::for_each(lst.begin(), lst.end(), [](double& x) {
				int count = static_cast<int>(10 * x + 10.5);
				for (int i = 0; i < count; ++i)
					std::cout << '*';
				std::cout << '\n';
			});*/
}





/**             second phase             */


/*[>* for simplicity, everything is public <]
struct List {
	struct Node {
		int _x;
		Node* _next;

		Node(int y): _x{y}, _next{nullptr} {}
	};

	// List
	Node* _head;
	List(): _head{nullptr} {}

	void insert(int x) {
		// insertion at the begining of list
		Node* node = new Node(x);
		node->_next = this->_head;
		this->_head = node;
	}
	~List() {
		Node* ptr = this->_head;
		while (ptr != nullptr) {
			Node* pptr = ptr;
			ptr = ptr->_next;
			delete pptr;
		}
		this->_head = nullptr;
	}

	int count() const;
};*/


/*void the_func(List& list) {
	for (int i = 0; i < 100; ++i)
		list.insert(i);
}*/


/*int main() {
	List list;
	std::vector<std::thread> workers;

	for (int i = 0; i < 10; ++i)
		workers.push_back(std::thread(the_func, std::ref(list)));

	[>* since, join is done within the scope, all the threads will finish
	 * before we exit the scope, so reference to list will be valid all of the
	 * time, however all of them sharing reference to same list <]
	std::for_each(workers.begin(), workers.end(), [](std::thread& th) {
					assert(th.joinable());
					th.join();
				});
	int total = list.count();
	std::cout << "total: " << total << '\n';
	// problem => sometimes, it gives other than 1000
}*/

/*int List::count() const {
	int count{};
	Node* ptr = this->_head;
	while (ptr != nullptr) {
		count++;
		ptr = ptr->_next;
	}
	return count;
}*/

/*****************************************/







/**         First Phase            */


/** first problem, you might see here, is that `variable(i) going out of scope`, but this can be solved(if we want that way) by putting join() in the scope of test function */

/** Even though, the reference is not stored in a container explicitly by a
 * thread for usage, there's still the problem which is that "Each thread has
 * its own stack, so when thread is created a new stack is allocated" and
 * whatever argument is passed to the thread constructor, they are copied on to
 * this stack, so when the thread function is called, it sees its argument in
 * the stack, in this case, it'll see a referece(the address of variable which
 * lives on different stack(main thread stack)) and this reference in this
 * program is going to survive longer than the data it's referring to(variable
 * itself). This could be solved by moving 'join()' into the scope of test()
 * (if we want that). When join(), is executed all threads will have finished
 * executing */

/** There's another problem, all these threads are sharing reference to the
 * same location and while the threads are starting, the value of at this
 * location is chaning. While the threads are executing, they are seeing a
 * momentary value of i. So i could be anything(2, 0, 7 etc.) and it has
 * nothing to do with 'i', when the constructor(of thread) was called. And the
 * value that the thread is seeing, depends on the timing of threads and this
 * type of dependency is called 'Race'(where one thread is writing and other
 * could be reading or also writing). */

/*void the_thread(int& i) {
	std::cout << "Hii! I'm thread " << i << '\n';
}*/

/*void test(std::vector<std::thread>& workers) {
	for (int i = 0; i < 10; ++i) {
		std::thread th(the_thread, std::ref(i));
		workers.push_back(std::move(th));
		assert(!th.joinable());
	}
}*/

/*int main(int argc, char **argv) {
	std::vector<std::thread> workers;
	test(workers);
	std::for_each(workers.begin(), workers.end(), [](std::thread& th) {
				assert(th.joinable());
				th.join();
			});
	return 0;
}*/


/***********************************/