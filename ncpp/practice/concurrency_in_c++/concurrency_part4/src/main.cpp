// main file

#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <exception>
#include <stdexcept>
#include <chrono>


/**         fourth phase          */

void the_func(int&& x) {
	std::cout << "Starting task\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Ending task\n";
}

int main() {
	std::future<void> ftr = std::async(the_func, 10);
	// thread execution is forced on:
	// 1. call of join()
	// 2. call on future::get()
	// 3. when the destructor of future object is called
	std::cout << "Exiting from main\n";
}

/*********************************/



/**         fourth phase          */

/*std::string the_func(int&& x) {
	throw(std::out_of_range("Execption from the_func"));
	return "Hello, I'm the_func and I got " + std::to_string(x);
}

// Exception passed through invisible channels between the task and calling
// thread

int main() {
	std::future<std::string> ftr = std::async(the_func, 10);
	std::cout << "Hello from main!!!\n";
	try {
		std::string str = ftr.get();
		std::cout << str << '\n';
	}
	catch (std::out_of_range& e) {
		e.what();
	}
}*/


/*********************************/








/**         third phase          */

/*std::string the_func(int&& x) {
	return "Hello, I'm the_func and I got " + std::to_string(x);
}

int main() {
	// async is used to create tasks
	std::future<std::string> ftr = std::async(the_func, 10);
	std::cout << "Hello from main!!!\n";
	std::string str = ftr.get();
	std::cout << str << '\n';
}*/



/*********************************/








/**         second phase          */

/*void the_func(std::promise<std::string>&& prms) {
	try {
		std::string str{"Hello from future!!!\n"};
		prms.set_value(str);
		throw(std::out_of_range("Exception from future!!!\n"));
	}
	catch(...) {
		prms.set_exception(std::current_exception());  // make a copy of the exception caught
	}
}

int main() {
	std::promise<std::string> prms;
	std::future<std::string> ftr = prms.get_future();

	std::thread th(the_func, std::move(prms));
	std::cout << "Hello from main!!!\n";
	th.join();
	try {
		std::string res = ftr.get();  // exception ends up here (rethrown)
		std::cout << res;
	}
	catch(std::out_of_range& e) {
		std::cout << e.what();
	}
}*/



/**         first phase          */


/** first you create a promise, a shared state is allocated automatically, this
 * is the state in which the value will be stored. The next stage, is to get
 * the future from the promise, by calling get_future(). At this point, shared
 * state is shared is shared between future and promise(and it's reference
 * bounded). Now, we create a thread and pass the promise to thread. 'promise'
 * is the input end of the channel, so it goes to new thread 'th' and future is
 * the output end of the channel and it stays with main thread here. 'shared
 * state' is now shared by these two threads and the synchronization is
 * provided by the system. Now, either promise sets the value or future tries
 * to get the value. If the future tries to get the value before promise sets
 * the value then it'll block and wait until promise sets the value. Say now,
 * promise is setting the input to shared state and then at the same time, the
 * state of shared state will change from empty to ready. If future was already
 * blocked trying to get the value, this signals 'main' thread to get the value
 * now, and then shared state changes to invalid state. This is because get()
 * can either pass by value or move the value. */

/** void the_func(std::promise<std::string>&& prms) {
//void the_func(std::promise<std::string>& prms) {
	//prms.set_value("Hello from Future!!!");

	// to see if the copying was done by future::get() we'll print the raw
	// pointer for string in both threads and match it
	// std::string str("Hello from future!!!");
	std::cout << (void*)str.data() << '\n';
	prms.set_value(str);
} */

/* int main(int argc, char **argv) {
	std::promise<std::string> prms;
	std::future<std::string> ftr = prms.get_future();

	// if you are going to move the prms(in thread), then you have to
	// get_future() before it, cause prms will be invalid after moving, if you
	// are just passing reference (std::ref()) then it's alright

	std::thread th(the_func, std::move(prms));
	//std::thread th(the_func, std::ref(prms));  // passing by reference
	std::cout << "Hello from main!!!\n";
	std::string res = ftr.get();
	std::cout << (void*)res.data() << '\n';
	std::cout << res << '\n';
	th.join();
	return 0;
} */


/*********************************/