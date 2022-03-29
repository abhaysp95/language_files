#include <iostream>
#include <limits>
#include <cmath>

void casting_and_rounding() {
	std::cout << __PRETTY_FUNCTION__ << "\n";
	double value1{10.9}, value2{15.9};
	int whole_number{static_cast<int>(value1) + static_cast<int>(value2)};

	/**
	 * static_cast reflects the fact that cast is checked statically.
	 * By adding explicit cast, you signal the compiler that a narrowing
	 * conversion is intentional.
	 * Above one simply discards the entire fractional part of the
	 * floating-point number.
	 */
	printf("%g, %ld, %lld\n", std::round(value1),
			std::lround(value1), std::llround(value1));
	std::cout << "------------------------" << std::endl;
}

void finding_the_limits() {
	std::cout << __PRETTY_FUNCTION__ << '\n';
	std::cout << "max(short): " << std::numeric_limits<short>::max() <<
		", min(short): " << std::numeric_limits<short>::min() << '\n';
	std::cout << "max(long double): " << std::numeric_limits<long double>::max() <<
		", min(long double): " << std::numeric_limits<long double>::min() << '\n';
	// you can get the range for other types in the same way too
	std::cout << "------------------------" << std::endl;
}

void finding_other_fundamental_types() {
	std::cout << __PRETTY_FUNCTION__ << '\n';
	// return number of binary digits, or bits
	std::cout << std::numeric_limits<bool>::digits << ", " <<
		std::numeric_limits<short>::digits << ", " <<
		std::numeric_limits<int>::digits << '\n';

	float positive_infinity = std::numeric_limits<float>::infinity();
	double negative_infinity = -std::numeric_limits<double>::infinity();
	long double not_a_number = std::numeric_limits<long double>::quiet_NaN();
	/**
	 * above functions will give special floating-point values for infinity and
	 * not-a-number(NaN)
	 * To check for infinity or NaN, use std::isinf() and std::isnan()
	 */
	std::cout << "------------------------" << std::endl;
}

void working_with_unicode_characters() {
	std::cout << __PRETTY_FUNCTION__ << '\n';
	// wide-character literals
	wchar_t wZ {L'Z'};
	wchar_t wch {L'\x0438'};  // prefix with L

	/**
	 * Type wchar_t doesn't handle international character sets very weel,
	 * much better to use char16_t for UTF-16 or char32_t for UTF-32 encoded
	 * characters.
	 */
	char16_t letter {u'B'};
	char16_t cyr {u'\x0438'};
	char32_t letter32 {u'B'};
	char32_t cyr32 {u'\x0438'};
	std::wcout << wZ << wch << '\n';  // for handling wchar_t
	std::cout << letter << cyr << letter32 << cyr32 << '\n';
	std::cout << "------------------------" << std::endl;
}

int main() {
	casting_and_rounding();
	finding_the_limits();
	finding_other_fundamental_types();
	working_with_unicode_characters();
}
