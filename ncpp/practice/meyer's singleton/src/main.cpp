// main file

#include <iostream>


// A singleton is a type instance for which there is one, and only one, object in the system

struct singleton_t {
	static singleton_t& instance() {
		static singleton_t s;
		return s;
	}  // instance

	singleton_t(const singleton_t&) = delete;
	singleton_t& operator=(const singleton_t&) = delete;

	private:
		singleton_t() {}
		~singleton_t() {}
};

/**
  1. static function objects are initialized when control flow hits the
	 function for the first time
  2. the lifetime of function static varialbes begins the first time the
	 program flow encounters the declaration and ends at program termination
  3. if control enters the declaration concurrently while the variable is being
	 initialized, the concurrent execution shall wait for completion of the
	 initialization

  Note: it is important to disable both the copy constructor and the assignment
  operator. The constructor and destructor are not exposed through the public
  interface
  */

int main(int argc, char **argv) {
	/* code here */
	return 0;
}