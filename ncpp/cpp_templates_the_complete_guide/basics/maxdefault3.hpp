#include <type_traits>

template<typename T1, typename T2,
	typename RT = std::common_type_t<T1, T2>>
RT max2(T1 a, T2 b)
{
	return b < a ? a : b;
}


// again, std::common_type_t<> decays, so that return value can't be a
// reference
