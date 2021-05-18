// main file

#include <iostream>
#include <algorithm>
#include <exception>

class iterator_out_of_bounds_exception: public std::exception {
	virtual const char* what() const throw() {
		return "iterator reached to end of collection already\n";
	}
};

class iterator_mismatch_exception: public std::exception {
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
				iterator& operator--(int) {
					iterator old = this->current;
					--(*this);
					return old;
				}
		};
	public:
		List() { init(); }
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
			List copy = rhs;
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
};

template<typename object>
void print_lst(const List<object>& lst) {
	for (const int& x: lst)
		std::cout << x << " ";
	std::cout << '\n';
}

int main(int argc, char **argv) {
	List<int> lst;
	lst.push_back(1);
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
	liter++;
	std::cout << *liter << '\n';
	//lst2.insert(liter, 20);  // throws "iterator_mismatch_exception"
	lst.insert(liter, 20);
	print_lst(lst);
	return 0;
}