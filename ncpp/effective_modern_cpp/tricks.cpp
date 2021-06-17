#include <iostream>
#include <array>

/** the ability to declare references to arrays enables
 * creation of template that deduces the number of elements
 * that an array contains */

template<typename T, std::size_t N>
constexpr std::size_t array_size(T (&)[N]) noexcept {
	return N;
}
/** declaring the above function constexpr makes its result
 * available during compilation, which makes possible to
 * declare, say, an array with the same number of elements as
 * a second array whose size is computed from braced
 * initializer */

template<typename T> struct TD;

void trick1() {
	int key_vals[] = {1, 2, 3, 4, 5, 6};
	//int mapped_vals[array_size(key_vals)];
	// or
	std::array<int, array_size(key_vals)> mapped_vals;
	std::cout << array_size(key_vals) << '\n';
	const char* names[] = {
		"this",
		"that",
		"these",
		"those"
	};
	/** T for names is deduced as const char *[4] */
	std::cout << array_size(names) << '\n';
}

int main(int argc, char** argv) {
	trick1();
}
