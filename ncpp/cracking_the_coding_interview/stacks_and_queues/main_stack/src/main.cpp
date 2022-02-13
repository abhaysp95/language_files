// main file

#include <iostream>

using namespace std;

template<typename Object>
class Stack {
	private:
		class Node {
			public:
				Object data;
				Node *next;
				Node(const Object &data, Node *next=nullptr)
					: data{data}, next{next} {}
				Node(Object &&data, Node *next=nullptr)
					: data{data}, next{next} {}
		};
		size_t _size;
		Node *_top;
		Node *_head;
		void _init() {
			_size = 0;
			_top = nullptr;
			_head = nullptr;
		}
	public:
		Stack() { this->_init(); }
		Stack(const std::initializer_list<Object>& lst) {
			this->_init();
			for(const Object& x: lst) this->enque(x);
		}
		Stack(Stack& rhs) {
			this->_init();
			Node* ptr = rhs._head;
			while(ptr != nullptr) {
				this->enque(ptr->data);
				ptr = ptr->next;
			}
			this->_size = rhs._size;
		}
		Stack(Stack&& rhs) {
			this->_init();
			std::swap(*this, rhs);
		}
		Stack& operator=(Stack& rhs) {

		}
};

int main(int argc, char **argv) {
	/* code here */
	return 0;
}