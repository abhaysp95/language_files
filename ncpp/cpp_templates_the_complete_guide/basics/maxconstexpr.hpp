template<typename T>
constexpr auto max(T a, T b)
{
	return b < a ? a : b;
}
