template<typename T>
auto max(T a, T b) -> decltype(true ? a : b)
{
	return b < a ? a : b;
}
