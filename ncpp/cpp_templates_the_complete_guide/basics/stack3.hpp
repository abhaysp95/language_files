#include <vector>
#include <cassert>

template<typename T, typename Cont = std::vector<T>>
class Stack
{
	private:
		Cont elems;
	public:
		void push(T const& elem);
		void pop();
		T const& top() const;
		bool empty() const
		{
			return elems.empty();
		}
};

template<typename T, typename Cont>
void Stack<T, Cont>::push(T const& elem)
{
	elems.push_back(elem);
}

template<typename T, typename Cont>
void Stack<T, Cont>::pop()
{
	cassert(!elems.empty());
	elems.pop_back();
}

template<typename T, typename Cont>
T const& Stack<T, Cont>::top() const
{
	assert(!elems.empty());
	return elems.back();
}
