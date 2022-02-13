#include <type_traits>


template<typename T1, typename T2,
	typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

// we can use operator?: directly. However, because we have to apply operator?:
// before call parameters a and b are declared, we can only use their types

// also, the usage of std::decay_t<> ensures that no reference can be
// returned(and also std::common_type_t<> also decays)

// But note that, above implementation requires that we are able to call
// default construcotrs for the passed types. There is another solution, using
// std::declval, which, however, makes the declaration even more compliecation

