#include <iostream>
#include <string>
#include <cstring>

// maximum of two values of any type(call by reference)
template<typename T>
T const& max(T const& a, T const& b)
{
	std::cout << __PRETTY_FUNCTION__ << '\n';
	return b < a ? a : b;
}

// maximum of two c-strings(call by value)
char const* max(char const* a, char const* b)
{
	std::cout << __PRETTY_FUNCTION__ << '\n';
	return strcmp(b, a) < 0 ? a : b;
}

// maximum of three values of any type(call by reference)
template<typename T>
T const& max(T const& a, T const& b, T const& c)
{
	std::cout << __PRETTY_FUNCTION__ << '\n';
	return max(max(a, b), c);
}

int main()
{
	auto m1 = ::max(7, 42, 68);

	char const* s1 = "frederic";
	char const* s2 = "anica";
	char const* s3 = "lucas";
	auto m2 = ::max(s1, s2, s3);
	return 0;
}
