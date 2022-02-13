#include <type_traits>

// C++14
template<typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 a, T2 b)
{
	return b < a ? a : b;
}

// C++11
/* template<typename T1, typename T2>
typename std::common_type<T1, T2>::type max(T1 a, T2 b)
{
	return b < a ? a : b;
} */

// std::common_type<> also decays
