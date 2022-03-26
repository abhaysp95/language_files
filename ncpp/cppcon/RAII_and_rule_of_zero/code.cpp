// a naive_vector for the purpose of demonstration of why RAII is needed

class naive_vector {
	private:
		int* _ptr;
		size_t _size;
	public:
		// this constructor correctly initialized _ptr with resource
		naive_vector(): _ptr{nullptr}, _size{0} {}
		void push_back(int new_value) {
			/** below 3 lines correctly replaces the resource managed by _ptr.
			 * No memory leaks here! */
			int* new_ptr = new int[this->_size + 1];
			std::copy(this->_ptr, this->_ptr + _size, new_ptr);
			delete[] this->_ptr;
			this->_ptr = new_ptr;
			this->_ptr[this->_size++] = new_value;
		}
};

void func() {
	naive_vector vec;  // _ptr initialized with 0 elements
	vec.push_back(1);  // _ptr is correctly updated with 1 element
	vec.push_back(2);  // _ptr is correctly updated with 2 element
}
/** Noticed problem ? We didn't cleaned the _ptr for the last time and exited
 * the function. We're just dropping the active pointer on the floor. We need
 * to delete[] the active pointer when the vector object is destroyed */



/** This is where the destructor is introduced, here is naive_vector again with
 * destructor */

class naive_vector {
	private:
		int* _ptr;
		size_t _size;
	public:
		naive_vector(): _ptr{nullptr}, _size{0} {}
		void push_back(int new_value) {
			int* new_ptr = new int[this->_size + 1];
			std::copy(this->_ptr, this->_ptr + _size, new_ptr);
			delete[] this->_ptr;
			this->_ptr = new_ptr;
			this->_ptr[this->_size++] = new_value;
		}
		~naive_vector() { delete[] this->_ptr; }
};

void func() {
	naive_vector vec;
	vec.push_back(1);
	vec.push_back(2);
}
/** now, the naive_vector doesn't leaks the memory on destruction(as destructor
 * is called at that time) */



/** But it still have bugs, consider this code block below for our latest naive_vector */

void func() {
	naive_vector v;
	v.push_back(1);
	{
		naive_vector w = v;  // copy constructor invoked
	}
	std::cout << v[0] << "\n";
}
/** In the nested scope, the line invokes implicitly generated(defaulted) copy
 * constructor of naive_vector. A default constructor simply copies each member.
 *
 * So, when that nested scope ends, destructor of naive_vector of "w" is
 * called and it frees the heap allocation(_ptr). And since both, w and v where
 * sharing same _ptr(pointer copies memory address), _ptr of v is also now
 * freed. So, v[0] is accessing memory that's already been freed and it's an
 * undefined behaviour. Also, when the scope of func() is going to end,
 * destructor of naive_vector for v will be invoked and this will give "double
 * delete"(double free) bug */

/** So, whenever you write destructor(and it's RAII approach), you probably
 * need to write copy constructor as well. The destructor is responsible for
 * freeing resource to avoid leaks. The copy constructor is responsible for
 * duplicating resources to avoid double frees. This applies to memory or other
 * resource you might be managing */

class naive_vector {
	private:
		int* _ptr;
		size_t _size;
	public:
		naive_vector(): _ptr{nullptr}, _size{0} {}
		void push_back(int new_value) {
			int* new_ptr = new int[this->_size + 1];
			std::copy(this->_ptr, this->_ptr + _size, new_ptr);
			delete[] this->_ptr;
			this->_ptr = new_ptr;
			this->_ptr[this->_size++] = new_value;
		}
		~naive_vector() { delete[] this->_ptr; }
		naive_vector(const naive_vector& rhs) {
			this->_ptr = new int[rhs._size];
			this->_size = rhs._size;
			std::copy(rhs._ptr, rhs._ptr + this->_size, this->_ptr);
		}
};



/** Now, let's clear something */

void func() {
	naive_vector v;
	v.push_back(1);
	naive_vector w = v;  // this calls copy constructor for w

	naive_vector x;
	x = v;  // this call assignment operator for x
}

/** Now, our default assignment operator also has the same problem(the one we
 * had with default copy constructor), that it could lead to undefined
 * behaviour or "double free" problem. So, if you write a destructor, you
 * probably need to write a copy constructor and if you write a copy
 * constructor, you probably need to write a copy assignment operator. Let's
 * write a copy constructor for our
 * naive_vector */

class naive_vector {
	private:
		int* _ptr;
		size_t _size;
	public:
		naive_vector(): _ptr{nullptr}, _size{0} {}
		void push_back(int new_value) {
			int* new_ptr = new int[this->_size + 1];
			std::copy(this->_ptr, this->_ptr + _size, new_ptr);
			delete[] this->_ptr;
			this->_ptr = new_ptr;
			this->_ptr[this->_size++] = new_value;
		}
		~naive_vector() { delete[] this->_ptr; }
		naive_vector(const naive_vector& rhs) {
			this->_ptr = new int[rhs._size];
			this->_size = rhs._size;
			std::copy(rhs._ptr, rhs._ptr + this->_size, this->_ptr);
		}
		void swap(naive_vector& rhs) noexcept {  // not too sure about this function
			std::swap(this->_size, rhs._size);
			// swap the pointer
			int* temp = rhs._ptr;
			rhs._ptr = this->_ptr;
			this->_ptr = temp;
		}
		naive_vector& operator=(const naive_vector& rhs) {
			naive_vector copy = rhs;
			copy.swap(*this);  //  this demonstrates the copy and swap idiom
			return *this;
		}
		// We need to write the swap(which will swap the pointer and swap the
		// size) and it can be noexcept
};




