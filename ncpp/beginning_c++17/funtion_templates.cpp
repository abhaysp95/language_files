#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

// template declaration
/* template<typename T>
const T& larger(const T& a, const T& b); */

// below template specialization works for this declaration, not the above one.
// How would you write specialized template for "int*" for above template
// declaration
template<typename T>
T larger(T a, T b);

// overload original with another (second, distinct) template
template<typename T>
T* larger(T* a, T* b);
// Now, with all these options, when does one need to use template specialization

// the definition of template specialization must come after the
// definition/declaration of original template
template <>
int* larger<int*>(int* a, int* b) {
	return *a > *b ? a : b;
}

// you can consider template specialization situation with function or template
// overload too
// function overload
int* larger(int* a, int* b) {
	return *a > *b ? a : b;
}

// template overload for array
template<typename T>
std::optional<T> larger(const T data[], size_t count) {
	if (count == 0) return std::nullopt;
	T max {data[0]};
	for (size_t i {1}; i < count; i++)
		if (max < data[i]) max = data[i];
	return max;
}

// template overload for vector
template<typename T>
std::optional<T> larger(const std::vector<T>& data) {
	if (data.empty())  return std::nullopt;
	T max {data.at(0)};
	for (const T& v: data)
		if (max < v) max = v;
	return max;
}
// apparently, function and template overloads needs to be placed above their
// first usage too

// A way to make compiler know return type with multiple template parameter is
// to provide another return type
template<typename TReturn, typename TArg1, typename TArg2>
TReturn larger(TArg1 a, TArg2 b) {
	return a > b ? a : b;
}

// A way for compiler to deduce return type would be with "auto"
/* template <typename T1, typename T2>
auto larger(T1 a, T2 b) {
	return a > b ? a : b;
} */

// another way is "trailing return type"
template <typename T1, typename T2>
auto larger(T1 a, T2 b) -> decltype(a > b ? a : b)
{
	return a > b ? a : b;
}
// The above means that "auto" doesn't always say to compiler that (return)
// type needs to be deduced, but may also say that (return) type specification
// may come at the end of the function header

// In context of template, decltype() specifier isn't always useful for
// trailing return types
template <typename T1, typename T2>
auto vector_product(const std::vector<T1>& data1, const std::vector<T2>& data2)
{
	// safeguard against the vector of different size
	const auto count = std::min(data1.size(), data2.size());

	decltype(data1[0] * data2[1]) sum {};
	for (size_t i {}; i < count; i++) sum += (data1[i] * data2[i]);

	return sum;
}
// decltype never evaluates the expression it is applied to. The expression is
// hypothetical, used by compiler to evaluate the type. Thus, it is safe to
// call the the template with empty vector (for the decltype)

// to avoid repeating partial expression for trailing decltype(), one can use
// decltype(auto). Remember that, decltype() and decltype(auto) isn't
// equivalent to return type deduction using auto. Because unlike auto,
// decltype() and decltype(auto) will deduce to reference types and preserve
// const specifiers. Whereas, auto almost always deduces to value type
template <typename T1, typename T2>
decltype(auto) larger(T1 a, T2 b)
{
	return a > b ? a : b;
}

// default values for template parameters
template <typename TReturn=double, typename TArg1, typename TArg2>
TReturn larger2(TArg1 a, TArg2 b)
{
	return a > b ? a : b;
}
// above is just to show default value usage, using such idea for return type
// is generally bad

// unlike function parameter, where you can provide default value only to last
// parameter, you have some flexibility here. In previous example, default
// value was provided to first parameter, it could middle or last too
template <typename TArg, typename TReturn=TArg>
TReturn larger2(TArg a, TArg b)
{
	return a > b ? a : b;
}

// Non-Type template parameters
// The type of non-type template parameters can be one of the following:
// an intergral type, like int or long
// an enumeration type
// a pointer or reference to an object type
// a pointer or a reference to function
// a pointer to a class member
// Compiler needs to be able to evaluate the arguments corresponding to nontype parameters at compile time
template <typename T, int lower, int upper>
bool is_in_range(const T& value)
{
	return (value <= upper) && (value >= lower);
}

// even better would be to provide the non-type parameters first
template <int lower, int upper, typename T>
bool is_in_range(const T& value)
{
	return (value <= upper) && (value >= lower);
}

// even better would be to use function parameters for the limits in this case.
// Function parameters give you the flexibility of being able to pass values
// that are calculated at runtime, whereas above you must supply the limits at
// compile time

// templates for functions with fixed-size array arguments
// this will be generelized from the signature like
// "double average(const double (&array)[10]);"
template <typename T, size_t N>
T average(const T (&array)[N]) {
	T sum {};
	for (size_t i {}; i < N; i++)
		sum += array[i];
	return sum / N;
}

// Exercise
template <typename T1, typename T2>
decltype(auto) plus(T1 a, T2 b)
{
	return a + b;
}

// specialization won't work I think
// overload
template <typename T1, typename T2>
decltype(auto) plus(T1* a, T2* b)
{
	return *a + *b;
}

int main(int argc, char** argv) {
	int big_int {1098342}, small_int {20};

	// guess what type did T deduced (write full derived type here)
	/* std::cout << *larger(&big_int, &small_int) << '\n';

	int data[5] = {20, 40, 10, 90, 50};
	std::optional<int> val = larger(data, 5);
	if (val) std::cout << *val << '\n';

	std::vector<int> data2 {20, 40, 10, 90, 50};
	val = larger(data2);
	if (val.has_value()) std::cout << val.value() << '\n'; */

	double big_double {8923.923};
	/* std::cout << larger(small_int, big_double) << '\n'; */

	std::cout << is_in_range<double, 0, 500>(big_double) << '\n';
	std::cout << is_in_range<0, 500>(big_double) << '\n';

	double doubles[2] {1.0, 2.0};
	double moreDoubles[] {1.0, 2.0, 3.0, 4.0, 5.0};
	double *pointer = doubles;
	int ints[] {1, 2, 3, 4, 5};
	std::cout << average(doubles) << '\n';
	std::cout << average(moreDoubles) << '\n';
	// std::cout << average<double, 3>(moreDoubles) << '\n';  // won't compile
	/* std::cout << average(pointer) << '\n';  // won't compile
	std::cout << average<5>(pointer) << '\n'; */
	std::cout << average(ints) << '\n';

	return 0;
}

template<typename T>
const T& larger(const T& a, const T& b) {
	return a > b ? a : b;
}

template<typename T>
T* larger(T* a, T* b) {
	std::cout << "here" << '\n';
	return *a > *b ? a : b;
}

//
