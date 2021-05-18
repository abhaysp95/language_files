// main file

#include <iostream>
#include <algorithm>

template<typename object>
class vctr {
	static const int SPARE_CAPACITY = 16;
	private:
		int _size;
		int _capacity;
		object* _objects;
	public:
		explicit vctr(int init_size = 0): _size{init_size},
				 _capacity{init_size + SPARE_CAPACITY} {
					 _objects = new object[this->_capacity];
		}
		vctr(const vctr& rhs): _size{rhs._size},
			_capacity{rhs._capacity}, _objects{nullptr} {
				this->_objects = new object[this->_capacity];
				std::copy(rhs._objects, rhs._objects + this->_capacity, this->_objects);
		}
		vctr& operator=(const vctr& rhs) {
			vctr copy = rhs;
			std::swap(*this, copy);
			return *this;
		}
		~vctr() {
			delete[] this->_objects;
		}
		vctr(vctr&& rhs): _size{rhs._size}, _capacity{rhs._capacity}, _objects{rhs._objects} {
			rhs._objects = nullptr;
			rhs._size = 0;
			rhs._capacity = 0;
		}
		vctr& operator=(vctr&& rhs) {
			std::swap(this->_size, rhs._size);
			std::swap(this->_capacity, rhs._capacity);
			std::swap(this->_objects, rhs._objects);
			return *this;
		}
		void resize(int new_size) {
			if (new_size > this->_capacity)
				reserve(new_size * 2);
			this->_size = new_size;
		}
		void reserve(int new_capacity) {
			if (new_capacity < this->_size)
				return;
			object* new_arr = new object[new_capacity];
			for (int k = 0; k < this->_size; ++k)
				new_arr[k] = std::move(this->_objects[k]);
			this->_capacity = new_capacity;
			std::swap(this->_objects, new_arr);
			delete[] new_arr;
		}
		object& operator[](int index) {
			return this->_objects[index];
		}
		const object& operator[](int index) const {
			return this->_objects[index];
		}
		bool empty() const {
			return size() == 0;
		}
		int size() const {
			return this->_size;
		}
		int capacity() const {
			return this->_capacity;
		}
		void push_back(const object& x) {
			if (this->_size == this->_capacity)
				reserve(2 * this->_capacity + 1);
			this->_objects[this->_size++] = std::move(x);
		}
		void pop_back() {
			--this->_size;
		}
		const object& back() const {
			return this->_objects[this->_size - 1];
		}

		typedef object* iterator;
		typedef const object* const_iterator;

		iterator begin() {
			return &this->_objects[0];
		}

		const_iterator begin() const {
			return &this->_objects[0];
		}
		iterator end() {
			return &this->_objects[size()];
		}
		const_iterator end() const {
			return &this->_objects[size()];
		}
};

template<typename object>
void print_vct(const vctr<object>& vct) {
	for (const object& x: vct)
		std::cout << x << " ";
	std::cout << '\n';
}

int main(int argc, char **argv) {
	vctr<int> vct;
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(4);
	vct.push_back(5);
	vctr<int> vct2 = vct;
	vctr<int> vct3;
	vct3 = vct2;
	print_vct(vct3);
	vct3.resize(8);
	vct3[5] = 6;
	vct3[6] = 7;
	vct3[7] = 8;
	print_vct(vct3);
	int num = vct[2];
	std::cout << num << '\n';
	num = 10;
	std::cout << num << '\n';
	print_vct(vct);
	print_vct(vct2);
	print_vct(vct3);
	return 0;
}