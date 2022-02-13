#include <iostream>
#include <memory>
#include <fstream>
#include <cassert>
#include <future>

// exclusive ownership(raw pointer)
//{
	//T *ptr = new T;
	//...
	//delete ptr;
//}

// unique_ptr template
/*template<class T, class Deleter>  // we'll show use of Deleter later(just know it is there)
class unique_ptr {
	private:
		T* _ptr = nullptr;
	public:
		// it also have move constructor, move assignment operator(but no copy
		// constructor or copy assignment operator)
		~unique_ptr() {
			delete _ptr;
		}
};*/

// unique_ptr is move-only
// raw_pointer is copyable(two address can hold the address(point to) same
// 'controlled object of type T'(in heap)), but with unique_ptr, you get
// exclusive ownership
// and so move constructor of unique_ptr, nulls out the source pointer(just
// like any general move constructor in RAII)


// there's also specialization for arbitrary cleanup in 'unique_ptr'
/*template<class T, class Deleter>
class unique_ptr {
	private:
		T *_ptr = nullptr;
		Deleter _d;
	public:
		// ... other stuffs
		~unique_ptr() {
			if(_ptr) _d(_ptr);
		}
};*/

// unique_ptr have specialization of array type
// like array of 'int' or 'Widget' etc.
/*template<class T, class Deleter>
class unique_ptr<T[], Deleter> {
	private:
		T *_ptr = nullptr;
	public:
		// .. other things
		~unique_ptr() {
			delete[] _ptr;  // or it can also have 'Deleter' work for deleting too(this one is default, if no Deleter given)
		}
};*/

// unique_ptr is always a template of two parameters(if you don't provide a
// second paramter, it is defaulted to std::default_delete<T>)
// so, generally it has 'std::default_delete'(and also a default_delete for
// arrays of T)
template<class T, class Deleter = std::default_delete<T>>
class unique_ptr {
	private:
		T *_ptr = nullptr;  // even this part is customizable, if 'Deleter::pointer' names a type, then this member will of that type, instead of T*
		Deleter _d;  // use Deleter assigned from constructor(if not it'll use 'default delete')
	public:
		// ... other stuffs
		~unique_ptr() {
			if(_ptr) _d(_ptr);
		}
};

template<class T>
struct default_delete {
	void operator()(T *p) const {
		delete p;
	}
};


// custom deleter can do neat things
struct FileCloser {
	void operator()(std::FILE *fp) const {
		assert(fp != nullptr);
		fclose(fp);
	}
};

void test() {
	std::FILE *fp = std::fopen("somefile.txt", "r");
	std::unique_ptr<FILE, FileCloser> uptr(fp);
	// when uptr will go out of scope, it'll call 'operator()' of FileCloser
	//std::unique_ptr<FILE, FileCloser> uptr = std::make_unique<FILE, FileCloser>(std::fopen("somefile.txt", "r"));
}


struct REQDeleter {
	void operator()(X509_REQ *p) const { X509_REQ_free(p); }
};

class MyCSR {
	private:
		std::unique_ptr<X509_REQ, REQDeleter> _p;
	public:
		explicit MyCSR(std::unique_ptr<X509_REQ, REQDeleter> p):
			_p(std::move(p)) {}
		// This constructor takes unique_ptr by value
		// Functions taking owning pointers by value are sometimes called 'sinks'
		// A "unique_ptr sink" clearly conveys transfer of ownership
		// To call this constructor at all, you must have a unique_ptr already - so, you must have ownership of X509_REQ structure. By taking your unique_ptr by value(by move), the constructor shows, it 'takes' ownership of that X509_REQ structure away from you
		// unique_ptr is glue between low-level, Non-RAII, raw resource(X509_REQ) and the high-level RAII buisness object(MyCSR)
};


// Rule of thumb for smart pointers:
/**
  * 1. treat smart-pointer types just like raw-pointer types
  *		1.1. pass by value
  *		1.2. return by value(ofcourse)
  *		1.3. passing a pointer by reference is usually a code smell
  *		1.4. same goes for smart pointers.
  * 2. a function taking unique_ptr by value shows the 'transfer of ownership'
  *		2.1. even shows exactly 'what' responsibility is being transferred, because the responsibility is encoded in the deleter type
  *		2.2. usually, the responsibility is simply "to call delete"
  *	3. smart pointers are frequently implementation details and glue
  *		3.1. to bake unique_ptr or shared_ptr into your "interface" might be a code smell. Try to deal in buisness classes like MyCSR instead
  */


// shared_ptr

// shared_ptr looks similar to unique_ptr in surface
void test2() {
	std::unique_ptr<int> uptr = std::make_unique<int>(42);
	std::shared_ptr<int> sptr = std::make_shared<int>(42);
	// but it is vastly more complicated on inside
}

// shared_ptr expresses shared ownership. Especially, 'reference counting'


// Simple reference counting
struct Widget {
	std::atomic<int> _usecount{1};
	Widget *retain() {
		++_usecount;
		return this;
	}
	void release() {
		if(--_usecount == 0) delete this;
	}
};

void test3() {
	Widget *p = new Widget;
	Widget *q = p->retain();
	p->release();
	q->release();
}


// shared_ptr type-erases the deleter

/**
  * shared_ptr, unlike unique_ptr places a layer of indirection between the
  * physical heap allocated object and notion of ownership
  * your shared_ptr instances are essentially participating in ref-counted
  * ownership of the 'control block'. The control block itself is the sole
  * arbiter of what it means to "delete the controlled object"
  */


// Goal of modern C++: avoid raw 'new' or 'delete'

/**
  * 1. Every new must have matching delete
  * 2. Stop using manual calls to delete(Use smart pointers)
  * But if we stop writing 'delete', mustn't we should stop writing 'new' ?
  */
//auto *w = new Widget();
//use(w);  // Is this code Ok? (no delete)

//std::shared_ptr<Widget> w(new Widget());
//use(w);  // Is this code any better

// If we're not using 'delete', we should also not use 'new'
// Whenever, we heap-allocate something, we'll use factory function that returns it 'already wrapped in smart pointer'

//auto w = std::make_shared<Widget>();
//use(w);


// btw, unique_ptr<T> is implicitly convertible to shared_ptr<T>
std::shared_ptr<Widget> sptr = std::make_unique<Widget>();  // vice-versa is not possible
