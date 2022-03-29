#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <string_view>
#include <iomanip>
#include <optional>
#include <memory>

int yield(const double array[][4], size_t size);
void find_words(std::vector<std::string>& words, const std::string& text, const std::string& seperators);
void find_words2(std::vector<std::string>& words, const std::string_view& text, std::string_view sep);
void list_words(const std::vector<std::string>& words);
std::optional<size_t> find_last(std::string_view string, char to_find, std::optional<size_t> start_index);
void larger(long *a, long *b);
void larger(const long* a, const long* b);
double power(double val, int idx);

void passing_multidimensional_array_to_function() {
	double beans[3][4] = {
		{1.0, 2.0, 3.0, 4.0},
		{2.0, 3.0, 4.0, 5.0},
		{3.0, 4.0, 5.0, 6.0},
	};

	std::cout << "yield: " << yield(beans, std::size(beans)) << '\n';
}

int yield(const double array[][4], size_t size) {
	double sum{};
	for (size_t i {}; i < size; i++)
		/* for (size_t j {}; j < std::size(array[i]); j++) {
			sum += array[i][j]; */
		for (const double n: array[i])  // range based loop
			sum += n;
	return sum;
}

void input_vs_output_parameter() {
	std::string text {};
	std::cout << "Enter some text terminated by * ";
	std::getline(std::cin, text, '*');

	std::string seperators {" ,;:?.\"!'\n"};
	std::vector<std::string> words {};

	// if string literal is passed as 3rd argument, program will still compile
	// and reference will lose its benefit, although you can still get the
	// length of seperator with strlen(string.c_str())
	find_words(words, text, seperators);
	// solution is using string_view which is equivalent to const std::string
	// (no change allowed through public interface), initializing and copying
	// string_view is very cheap, so you can just use std::string_view instead
	// of "const std::string_view&"
	find_words2(words, text,  " ,;:?.\"!'\n");
	list_words(words);
}

// find_words find the words seperated by seperators from text
void find_words(std::vector<std::string>& words, const std::string& text, const std::string& seperators) {
	size_t start {text.find_first_not_of(seperators)};
	size_t end {};

	while (start != std::string::npos) {
		end = text.find_first_of(seperators, start + 1);
		if (end == std::string::npos)
			end = text.length();

		words.push_back(text.substr(start, end - start));
		start = text.find_first_not_of(seperators, end + 1);
	}
}

void find_words2(std::vector<std::string>& words, const std::string_view& text, std::string_view sep) {
	size_t start {text.find_first_not_of(sep)};
	size_t end {};

	while (start != std::string_view::npos) {
		end = text.find_first_of(sep, start + 1);
		if (end == std::string_view::npos)
			end = text.length();

		words.push_back(std::string{text.substr(start, end - start)});
		// std::string_view doesn't allow implicit conversion to std::string
		// for very obvious reason and doesn't provide c_str() but provides
		// data() method (c++17)
		start = text.find_first_not_of(sep, end + 1);
	}
}

void list_words(const std::vector<std::string>& words) {
	std::cout << "Your string contains the following " << words.size() << " words:\n";
	size_t count {};

	for (const std::string& word: words) {
		std::cout << std::setw(15) << word;
		if (!++count%5)
			std::cout << '\n';
	}
	std::cout << std::endl;
}

void working_with_optional_values() {  // std::optional
	const auto string = "Growing old is mandatory; growing up is optional";

	const std::optional<size_t> found_a {find_last(string, 'a', std::nullopt)};
	if (found_a) {
		std::cout << "Found the last a at index " << *found_a << std::endl;
		// std::optional does behaves like pointer but it isn't a pointer,
		// copying an optional<> always involves copying the entire value
		// that's stored in it
		// std::optional<std::string> os {"something"};
		// (*os).size() & os->size() will be same thing
	}

	const auto found_b {find_last(string, 'b', std::nullopt)};
	if (found_b.has_value()) {
		std::cout << "Found the last b at index " << found_b.value() << std::endl;
	}

	// const size_t found_c {find_last(string, 'c')};  // can't convert to size_t

	const auto found_early_i {find_last(string, 'i', 10)};
	if (found_early_i != std::nullopt) {
		std::cout << "Found an early i at index " << *found_early_i << std::endl;
	}
}

std::optional<size_t> find_last(std::string_view str, char to_find, std::optional<size_t> start_index) {
	// code below will not work for empty strings
	if (str.empty()) {
		return std::nullopt;  // or: 'return optional<size_t>', or: 'return {}'
	}

	// determine the starting index for the loop that follows
	size_t index = start_index.value_or(str.size() - 1);

	while (true) {  // never use while (index >= 0) here, size_t is always >= 0
		if (str[index] == to_find) return index;
		if (index == 0) return std::nullopt;
		--index;
	}
}

void recursive_power() {
	for (int i {-3}; i <= 3; i++) {
		std::cout << std::setw(10) << power(8.0, i);
	}
	std::cout << std::endl;
}

double power(double val, int idx) {
	if (idx == 0) return 1;
	else if (idx > 1) return val * power(val, idx - 1);
	else return (1.0 / power(val, -idx));
}

// const type* can only be passed to parameter type having const, but a
// non-const can be passed to both non-const and const parameter, in case you
// pass one const and one non-const, the function with both const type will be
// used, unless you specified such function signature to be used
void larger(long *a, long *b) {
	std::cout << "without const" << std::endl;
}

void larger(const long *a, const long *b) {
	std::cout << "with const" << std::endl;
}

// Quick Sort

using Words = std::vector<std::shared_ptr<std::string>>;

void extract_words(Words& words, std::string_view text, std::string_view seperator);
void sort(Words& words);
void sort(Words& words, size_t start, size_t end);
void swap(Words& words, size_t first, size_t seconds);
void show_words(const Words& words);
size_t max_word_length(const Words& words);

void quicksort() {
	Words words {};
	std::string text;
	std::string seperators {" ,;:?.\"!'\n"};

	std::getline(std::cin, text, '*');

	extract_words(words, text, seperators);

	sort(words);
	show_words(words);
}

void extract_words(Words& words, std::string_view text, std::string_view seperator) {
	size_t start {text.find_first_not_of(seperator)};
	size_t end {};

	while (start != std::string_view::npos) {
		end = text.find_first_of(seperator, start + 1);
		if (end == std::string_view::npos) end = text.length();
		words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));
		start = text.find_first_not_of(seperator, end + 1);
	}
}

void swap(Words& words, size_t first, size_t second) {
	auto temp{words[first]};
	words[first] = words[second];
	words[second] = temp;
}

void sort(Words& words) {
	if (!words.empty())
		sort(words, 0, words.size() - 1);
}

void sort(Words& words, size_t start, size_t end) {
	if (!(start < end))
		return;

	// choose the middle address to partition set
	swap(words, start, (start + end) / 2);  // swap middle address with start

	size_t current {start};
	for (size_t i {start + 1}; i <= end; i++) {
		if (*words[i] < *words[start])  // Is word less than chosen word
			swap(words, ++current, i);  // so, swap to left
	}

	swap(words, start, current);  // swap choosen and last swapped word

	if (current < start) sort(words, start, current - 1);  // sort left subset if exists
	if (end > current + 1) sort(words, current + 1, end);  // sort right subset if exists
}

void show_words(const Words& words) {
	const size_t field_width {max_word_length(words)};
	const size_t words_per_line {8};
	std::cout << std::left << std::setw(field_width) << *words[0];  // output the first word

	size_t words_in_line {};
	for (size_t i {1}; i < words.size(); i++) {
		if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line) {
			words_in_line = 0;
			std::cout << '\n';
		}
		std::cout << std::setw(field_width) << *words[i];
	}
	std::cout << std::endl;
}

size_t max_word_length(const Words& words) {
	if (words.empty()) return 0;

	size_t max_len {words[0]->size()};
	for (const auto& word: words) {
		if (max_len < word->size()) max_len = word->length();
	}
	return max_len;
}

int main() {
	/* passing_multidimensional_array_to_function();
	working_with_optional_values(); */
	long a {10}, b {20};
	const long c {20}, d {20};
	larger(&a, &b);
	larger(&c, &d);
	larger(&a, &c);
}
