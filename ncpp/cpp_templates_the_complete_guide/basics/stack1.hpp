#include <vector>
#include <cassert>
#include <iostream>

template<typename T>
class Stack
{
	private:
		std::vector<T> elems;
	public:
		// inside a class template using the class name not followed by
		// template arguments represents the classwith its template parameters
		// as its arguments(just like this copy constructor)
		Stack(Stack& other);
		// <T> singlas special handling of special template paramters, so
		// usually better to use the first form(for outside the class case, see operator== at last)
		Stack<T>& operator=(Stack<T> const& other);
		void push(T const& elem);
		void pop();
		T const& top() const;
		bool empty() const { return elems.empty(); }
		void printOn(std::ostream& os) const;
		// this means that operator<< for class Stack<> is not  a function
		// template, but an "ordinary" function instantiated with the class
		// template if needed
		/* friend std::ostream& operator<<(std::ostream& os, Stack<T> const& s)
		{
			s.printOn(os);
			return os;
		} */
		// however, when trying to declare the friend function and define it
		// afterwards, we have two options(commenting above friend definition)
		// 1. we can implicitly declare a new function template, which must use
		//          a different template parameter, such as U
		template<typename U>
		friend std::ostream& operator<<(std::ostream& os, Stack<U> const& s);
		// 2. we can forward declare the output operator for a Stack<T> to be a
		//          template, which , however, means that we have to forward
		//          declare Stack<T>
};

// all these method definitions could be done as inline(inside class too)
template<typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
	assert(!elems.empty());
	elems.pop_back();
}

template<typename T>
T const& Stack<T>::top() const
{
	assert(!elems.empty());
	return elems.back();
}

template<typename T>
bool operator==(Stack<T> const& lhs, Stack<T> const& rhs)
{
	// stuff
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Stack<T> const& s)
{
	s.printOn(os);
	return os;
}
