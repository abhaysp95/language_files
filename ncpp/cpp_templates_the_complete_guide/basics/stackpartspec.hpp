#include "stack1.hpp"

template<typename T>
class Stack<T*> {
	private:
		std::vector<T*> elems;
	public:
		void push(T* elems);
		T* pop();
		T* top() const;
		bool empty() const
		{
			return elems.empty();
		}
};

template<typename T>
void Stack<T*>::push(T* elem)
{
	elems.push_back(elem);
}

template<typename T>
T* Stack<T*>::pop()
{
	cassert(!elems.empty());
	T* elem = elems.back();
	elems.pop_back();
	return elem;
}

template<typename T>
T* Stack<T*>::top() const
{
	return elems.back();
}
