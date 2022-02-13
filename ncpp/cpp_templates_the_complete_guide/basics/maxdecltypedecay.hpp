// it might happen that return type is a reference type, because under some
// conditions T might be a reference. For this reason you should return the
// type decayed from T

#include <type_traits>

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type
{
	return b < a ? a : b;
}

// std::decay<> returns the resulting type in a member type. It is defined by
// the standard librarr in <type_trait>. Because member type is a type, you
// have to qualify the expression with 'typename' to access it

// iniitailization of type 'auto' always decays. This also applies to return
// values when the return type is just 'auto'
