// main file

#include <iostream>
#include <algorithm>
#include <exception>

class iterator_out_of_bounds_exception: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "iterator reached to end of collection already\n";
		}
};

class iterator_mismatch_exception: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "iterator not matched\n";
		}
};

template<typename object>
class List {
	private:
		struct Node {
			object data;
			Node* prev;
			Node* next;
			Node(const object& d = object{}, Node* p = nullptr, Node* n = nullptr)
				: data{d}, prev{p}, next{n} {}
			Node(object&& d, Node* p = nullptr, Node* n = nullptr)
				: data{d}, prev{p}, next{n} {}
		};
	private:
		int _size;
		Node* _head;
		Node* _tail;
		void init() {
			this->_size = 0;
			this->_head = new Node;
			this->_tail = new Node;
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
		}
	public:
		class const_iterator {
			protected:
				const List<object> *the_list;
				Node* current;
				object& retrieve() const { return current->data; }
				const_iterator(const List<object>& lst, Node* p): the_list{&lst}, current{p} {}
				void assert_is_valid() const {
					if (this->the_list == nullptr || this->current == nullptr
							|| this->current == this->the_list->_head)
						throw iterator_out_of_bounds_exception{};
				}
				friend class List<object>;
			public:
				const_iterator(): current{nullptr} {}
				const object& operator*() const { return retrieve(); }
				const_iterator& operator++() {
					this->current = this->current->next;
					return *this;
				}
				const_iterator operator++(int) {
					const_iterator old = *this;
					++(*this);
					return old;
				}
				const_iterator& operator--() {
					this->current = this->current->prev;
					return *this;
				}
				const_iterator& operator--(int) {
					const_iterator old = *this;
					--(*this);
					return old;
				}
				const_iterator& operator+(object x) {
					assert_is_valid();
					const_iterator temp = *this;
					while (x--) {
						assert_is_valid();
						++temp;
					}
					this->current = temp.current;
					return *this;
				}
				const_iterator& operator-(object x) {
					assert_is_valid();
					const_iterator temp = *this;
					while (x--) {
						assert_is_valid();
						--temp;
					}
					this->current = temp.current;
					return *this;
				}
				bool operator==(const const_iterator& rhs) const {
					return this->current == rhs.current;
				}
				bool operator!=(const const_iterator& rhs) const {
					return !(*this == rhs);
				}
		};
		class iterator: public const_iterator {
			protected:
				iterator(const List<object>& lst, Node* p): const_iterator{lst, p} {}
				friend class List<object>;
			public:
				iterator() {}
				object& operator*() { return const_iterator::retrieve(); }
				const object& operator*() const {
					return const_iterator::operator*();
				}
				iterator& operator++() {
					this->current = this->current->next;
					return *this;
				}
				iterator operator++(int) {
					iterator old = *this;
					++(*this);
					return old;
				}
				iterator& operator--() {
					this->current = this->current->prev;
					return *this;
				}
				iterator operator--(int) {
					iterator old = this->current;
					--(*this);
					return old;
				}
				iterator& operator+(object x) {
					const_iterator::assert_is_valid();
					iterator temp = *this;
					while (x--) {
						const_iterator::assert_is_valid();
						++temp;
					}
					this->current = temp.current;
					return *this;
				}
				iterator& operator-(object x) {
					const_iterator::assert_is_valid();
					iterator temp = *this;
					while (x--) {
						const_iterator::assert_is_valid();
						--temp;
					}
					this->current = temp.current;
					return *this;
				}
		};
		class const_reverse_iterator {
			protected:
				const List<object> *the_list;
				Node* current;
				object& retrieve() const { return current->data; }
				const_reverse_iterator(const List<object>& lst, Node* p): the_list{&lst}, current{p} {}
				void assert_is_valid() const {
					if (this->the_list == nullptr || this->current == nullptr
							|| this->current == this->the_list->_tail)
						throw iterator_out_of_bounds_exception{};
				}
				friend class List<object>;
			public:
				const_reverse_iterator(): current{nullptr} {}
				const object& operator*() const { return retrieve(); }
				const_reverse_iterator& operator++() {
					this->current = this->current->prev;
					return *this;
				}
				const_reverse_iterator& operator++(int) {
					const_reverse_iterator old = *this;
					++(*this);
					return old;
				}
				const_reverse_iterator& operator--() {
					this->current = this->current->next;
					return *this;
				}
				const_reverse_iterator& operator--(int) {
					const_reverse_iterator old = *this;
					--(*this);
					return old;
				}
				const_reverse_iterator& operator+(object x) {
					assert_is_valid();
					const_reverse_iterator temp = *this;
					while (x--) {
						assert_is_valid();
						++temp;
					}
					this->current = temp.current;
					return *this;
				}
				const_reverse_iterator& operator-(object x) {
					assert_is_valid();
					const_reverse_iterator temp = *this;
					while (x--) {
						assert_is_valid();
						--temp;
					}
					this->current = temp.current;
					return *this;
				}
				bool operator==(const const_reverse_iterator& rhs) const {
					return this->current == rhs.current;
				}
				bool operator!=(const const_reverse_iterator& rhs) const {
					return !(*this == rhs);
				}
		};
		class reverse_iterator: public const_reverse_iterator {
			protected:
				reverse_iterator(const List<object>& lst, Node* p): const_reverse_iterator{lst, p} {}
				friend class List<object>;
			public:
				reverse_iterator() {}
				object& operator*() { return const_reverse_iterator::retrieve(); }
				const object& operator*() const {
					return const_reverse_iterator::operator*();
				}
				reverse_iterator& operator++() {
					this->current = this->current->prev;
					return *this;
				}
				reverse_iterator operator++(int) {
					reverse_iterator old = *this;
					++(*this);
					return old;
				}
				reverse_iterator& operator--() {
					this->current = this->current->next;
					return *this;
				}
				reverse_iterator operator--(int) {
					reverse_iterator old = *this;
					--(*this);
					return old;
				}
				reverse_iterator& operator+(object x) {
					const_reverse_iterator::assert_is_valid();
					reverse_iterator temp = *this;
					while (x--) {
						const_reverse_iterator::assert_is_valid();
						++temp;
					}
					this->current = temp.current;
					return *this;
				}
				reverse_iterator& operator-(object x) {
					const_reverse_iterator::assert_is_valid();
					reverse_iterator temp = *this;
					while (x--) {
						const_reverse_iterator::assert_is_valid();
						--temp;
					}
					this->current = temp.current;
					return *this;
				}
		};
	public:
		List() { init(); }
		List(std::initializer_list<object> lst) {
			init();
			for (auto& x: lst)
				push_back(x);
		}
		~List() {
			clear();
			delete this->_head;
			delete this->_tail;
		}
		List(const List& rhs) {
			init();
			for (auto& x: rhs) // try object instead of auto here
				push_back(x);
		}
		List& operator=(const List& rhs) {
			List copy = rhs;  // don't confuse this with assignment operation(it calls copy constructor)
			std::swap(*this, copy);
			return *this;
		}
		List(List&& rhs): _size{rhs._size}, _head{rhs._head}, _tail{rhs._tail} {
			rhs._size = 0;
			rhs._head = nullptr;
			rhs._tail = nullptr;
		}
		List& operator=(List&& rhs) {
			std::swap(this->_size, rhs._size);
			std::swap(this->_head, rhs._head);
			std::swap(this->_tail, rhs._tail);
			return *this;
		}
		iterator begin() {
			iterator iter{*this, this->_head};
			return ++iter;
		}
		//const_iterator begin() const { return this->_head->next; }
		const_iterator begin() const {
			const_iterator iter{*this, this->_head};
			return ++iter;
		}
		iterator end() {
			iterator iter{*this, this->_tail};
			return iter;
		}
		//const_iterator end() const { return this->_tail; }
		const_iterator end() const {
			const_iterator iter{*this, this->_tail};
			return iter;
		}
		reverse_iterator rbegin() {
			reverse_iterator iter{*this, this->_tail};
			return ++iter;
		}
		const_reverse_iterator rbegin() const {
			const_reverse_iterator iter{*this, this->_tail};
			return ++iter;
		}
		reverse_iterator rend() {
			reverse_iterator iter{*this, this->_head};
			return iter;
		}
		const_reverse_iterator rend() const {
			const_reverse_iterator iter{*this, this->_head};
			return iter;
		}
		int size() { return this->_size; }
		bool empty() { return size() == 0; }
		void clear() {
			while (!empty())
				pop_front();
		}
		object& front() { return *begin(); }
		const object& front() const { return *begin(); }
		object& back() { return *--end(); }
		const object& back() const { return *--end(); }
		void push_front(const object& x) { insert(begin(), x); }
		void push_front(object&& x) { insert(begin(), std::move(x)); }
		void push_back(const object& x) { insert(end(), x); }
		void push_back(object&& x) { insert(end(), std::move(x)); }
		void pop_front() { erase(begin()); }
		void pop_back() { erase(--end()); }
		iterator insert(iterator iter, const object& x) {
			iter.assert_is_valid();
			if (iter.the_list != this)
				throw iterator_mismatch_exception{};
			Node* p = iter.current;
			this->_size++;
			return { *this, p->prev = p->prev->next = new Node{x, p->prev, p} };
		}
		iterator insert(iterator iter, object&& x) {
			iter.assert_is_valid();
			if (iter.the_list != this)
				throw iterator_mismatch_exception{};
			Node* p = iter.current;
			this->_size++;
			return { *this, p->prev = p->prev->next = new Node{std::move(x), p->prev, p} };
		}
		iterator erase(iterator iter) {
			Node* p = iter.current;
			iterator ret_val{*this, p->next};
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			this->_size--;
			return ret_val;
		}
		iterator erase(iterator from, iterator to) {
			for (iterator iter = from; iter != to;)
				iter = erase(iter);
			return to;
		}

		/****************  Exercise 2 ********************/

		void swap_adjacent_single(object data) {
			// I'll be swapping it with next element
			Node* ptr = this->_head;
			Node* pptr = ptr;
			while (ptr->data != data && ptr->next != nullptr) {
				pptr = ptr;
				ptr = ptr->next;
			}
			if (ptr->next == nullptr)
				std::cout << "No node with matching data found\n";
			else {
				pptr->next = ptr->next;
				ptr->next = ptr->next->next;
				pptr->next->next = ptr;
			}
		}
		void swap_adjacent_double(object data) {
			// again, swaping with next element
			Node* ptr = this->_head;
			while (ptr->data != data && ptr->next != nullptr) {
				ptr = ptr->next;
			}
			if (ptr->next == nullptr)
				std::cout << "No node found\n";
			else {
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				ptr->next->next->prev = ptr;
				if (ptr->next->next != nullptr)
					ptr->next->next->prev = ptr;
				ptr->prev = ptr->next;
				ptr->next = ptr->next->next;
				ptr->prev->next = ptr;
			}
		}

		/***********************************************/

		/****************  Exercise 15 ********************/

		void splice(iterator position, List<object>& lst) {
			iterator iter = position;
			if (iter.the_list != position.the_list)
				throw iterator_mismatch_exception{};
			while (!lst.empty()) {
				object x = lst.back();
				lst.pop_back();
				iter = insert(iter, x);
			}
		}

		/*************************************************/
};

template<typename object>
void print_lst(const List<object>& lst) {
	for (const int& x: lst)
		std::cout << x << " ";
	std::cout << '\n';
}


/****************** Exercise 1 ************/


void printLots(const List<int>& lst1, const List<int>& lst2) {
	List<int>::const_iterator iter = lst2.begin();
	int prev{};
	for (const int& x: lst1) {
		iter + (x - prev);
		std::cout << *iter << ' ';
		prev = x;
	}
	std::cout << '\n';
}

/******************************************/


/****************** Exercise 3 ************/

template<typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& x) {
	typename List<Object>::iterator iter = start;
	for (;iter != end; ++iter) {
		if (*iter == x)
			break;
	}
	return iter;
}

/******************************************/


void exercise1() {
	List<int> p{1, 3, 4, 6};
	List<int> l{10, 20, 30, 40, 50, 60, 70, 80};
	printLots(p, l);
	/** not part of exercise, just to check memory leak */
	try {
		throw iterator_mismatch_exception{};
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	/****************************************************/
}

void exercise2() {
	List<int> lst1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print_lst(lst1);
	lst1.swap_adjacent_single(5);
	print_lst(lst1);
	lst1.swap_adjacent_double(8);
	print_lst(lst1);
}

void exercise3() {
	List<int> lst{2, 3, 5, 1, 9, 10, 8, 4, 3};
	List<int>::iterator iter = find(lst.begin(), lst.end(), 8);
	std::cout << (iter != lst.end() ? "Element found\n" : "Element not found\n");
	iter = find(lst.begin(), lst.end(), 20);
	std::cout << (iter != lst.end() ? "Element found\n" : "Element not found\n");
}

void exercise15() {
	List<int> lst{8, 9, 10};
	List<int> lst2{4, 5, 6, 7};
	lst.splice(lst.begin(), lst2);
	print_lst(lst);
}

void exercise16() {
	List<int> L{2, 4, 6, 8, 10};
	List<int>::reverse_iterator iter = L.rbegin();
	while (iter != L.rend())
		std::cout << *iter++ << ' ';
	std::cout << "\n";
}

int main(int argc, char **argv) {
	exercise1();
	exercise2();
	exercise3();
	exercise15();
	exercise16();




	/*List<int> lst;
	lst.push_back(1);
	print_lst(lst);
	try {
		throw 0;
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	print_lst(lst);
	lst.push_front(10);
	std::cout << lst.back() << '\n';
	print_lst(lst);
	List<int> lst2 = lst;
	print_lst(lst2);
	List<int> lst3;
	lst3 = lst2;
	print_lst(lst3);
	List<int>::iterator liter = lst.begin();
	//liter++;
	liter + 1;
	std::cout << *liter << '\n';
	List<int>::iterator iiter = lst.insert(liter, 20);
	std::cout << *iiter << '\n';
	print_lst(lst);*/


	/** this finally works, no memory leaks */

	List<int> lst{100, 200, 300, 400};
	List<int> lst2 = lst;
	List<int>::iterator liter = lst.begin();
	try {
		lst2.insert(liter, 20);  // throws "iterator_mismatch_exception"
	}
	catch (iterator_mismatch_exception& e) {
		std::cout << e.what();
	}

	/***************************************/

	return 0;
}