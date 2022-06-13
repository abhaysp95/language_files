#ifndef AVERAGE_H
#define AVERAGE_H

#include <type_traits>
#include <vector>
#include <cassert>

template <typename T>
T average(const std::vector<T>& values)
{
	static_assert(std::is_arithmetic_v<T>,
			"Type parameter for average() should be arithmetic");
	assert(!values.empty());  // not possible with static_assert

	T sum{};
	for (auto val: values)
		sum += val;

	return sum;
}

#endif
