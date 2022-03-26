/** Starting with heap */

/** STL heap has property, where parent is bigger than it's children, we can also sqaush the heap and make it an array(or vector) and vice-versa */

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void print_vec(const std::vector<T>& vec) {
	for (const T& x: vec) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}


/**************************
*  LAND OF PERMUATATIONS  *
**************************/

// The place where element move around the collections even if they don't
// change value


/** Province of Heaps */
void heap_func() {
	std::vector<double> numbers{0,1,2,3,4,5,6,7,8,9};
	//std::make_heap(begin(numbers), end(numbers));
	// or
	std::make_heap(numbers.begin(), numbers.end());
	print_vec(numbers);
	// when we add a new node to heap, we need to re-arrange it to satisfy the
	// heaps property, so let's say we add a new number to "numbers"(which is
	// now squashed heap), how will we re-arrange it ?
	numbers.push_back(8.88);
	// we'll use push_heap() to re-arrange
	std::push_heap(numbers.begin(), numbers.end());
	print_vec(numbers);
	// one of the benefits of using heap, is that we can get max element in no
	// time
	std::pop_heap(numbers.begin(), numbers.end());
	print_vec(numbers);
	//numbers.pop_back();
	//print_vec(numbers);
	/** but let's say we don't pop_back() and we continue to do this operation
	 * of pop_heap() again and again, we'll get a sorted collection */
}

/** Shore of Sorting */
void sort_func() {
	// sort -> sorts the container

	// partial_sort -> LHS of the collection is what would be there, if the
	// collection was completely sorted, but RHS can be in unspecified order

	// nth_element -> sorts container in such a way, that would tell, what
	// would be at nth index if the container was completely sorted, LHS of the
	// container would in unspecified order but less the asked "nth element"
	// and RHS would be greater but also in unspecified order

	// sort_heap -> repeatedly calling pop_heap() to sort the heap(squashed form)

	// implace_merge -> where the two halves of container are in sorted order
	// but not the container itself, and just like the merge sort, this would
	// merge the container in sorted order
}

void paritiion() {
	// parition -> partition means to put the elements for which the predicate
	// satisfies before those elements which don't satifsy predicates

	// parition_point -> a 'parition point' is a point which is just after the
	// last element which satisfies the predicate and is the first one which
	// doesn't
}

void other_permutation() {
	// rotate -> takes element at the end and puts it in begining and probably
	// vice-versa too

	// shuffle -> change the order of collection randomly

	/** Suppose, you are provided with collection of numbers and now, so */

	// next_permutation -> would get you the next collection order of what will
	// come from the collection of number

	/** Example: 1, 2, 3, 4, 5, 6, 7, 8, 9
	  next_permutaton -> 1, 2, 3, 4, 5, 6, 7, 9, 8
	  next_permutaton -> 1, 2, 3, 4, 5, 6, 8, 7, 9
	*/

	// prev_permutation -> would be vice-versa of next_permutation

	// reverse -> reverses the order of element in collection
}


/** Secret Runes */
// things which you can combine with other algorithms to generate new algorithms

void secret_runes() {
	// stable_* ==>
	//	1. stable_sort
	//	2. stable_partition

	/** Ex: think of it as with "partition" all the element satisfying
	 * predicate will get to the begining, that's for sure, but in that
	 * process, there order could also get changed. Like, say the collection
	 * was in sorted order and if you perform "stable_partition", then the two
	 * partition(one satisfying predicate and other not) will also be in sorted
	 * order.
	 * Something, same could be said for stable sort too, like you have
	 * collection of words and you want to sort them in order the length of the
	 * words but also you want to keep them in alphabetical order */

	// is_* ==>
	//	1. is_sort
	//	2. is_partition
	//	3. is_heap

	/** These returns boolean to tell whether the collection is sorted or
	 * partitioned or is heap or not etc. */

	// is_*_until ==>
	//	1. is_sorted_until
	//	2. is_partitioned_until
	//	3. is_heap_until

	/** Returns an iterator, that's the first position, where the predicate
	 * doesn't hold anymore. Ex:, if we have a sorted collection and if we call
	 * "is_sorted_until", we will get end of that collection as iterator */
}



/********************
*  LAND OF QUERIES  *
********************/


void numeric_algorithms() {
	// count -> takes begin, end and value and returns how many times value
	// occured in collection

	// accumulate -> generally, sums the elements of collection(or any other
	// operation you pas)

	// reduce -> practically same as accumulate, but takes no initial value and
	// optionally execution policy(C++17 feature, allows programmers to ask for
	// algorithms to be parallelised)(C++17)

	// partial_sum -> sum from first position to a point(with somewhat
	// accumulate like operation)

	// inclusive_scan -> same thing as partial_sum except it can be run in
	// parallel(C++17)

	// exclusive_scan -> same as inclusive_scan except it doesn't include
	// current element(C++17)

	// transform_inclusive_scan -> first transform, then perform inclusive
	// scan(C++17)

	// transform_exclusive_scan -> first transform, then perform exclusive
	// scan(C++17)

	// inner_product -> it is multiplication of counter part elements and then
	// summing the whole thing

	// adjacent_difference -> difference between every two neighbours in the
	// collection

	// sample -> takes something which can generate random numbers(and takes a
	// number say 'n') and it produces n element of that collection, selected
	// randomly(C++17)
}


// quering property on one range
void quering_a_property() {
	// all_of -> takes collection and predicate and returns if "all of" the
	// element satisfy the predicate. With empty collection([)), it returns
	// "true"

	// any_of -> if atleast one element satisfy the predicate, with [), it
	// returns "false"

	// none_of -> if no element satisfy the predicate, with [), it returns
	// "true"
}


// quering property on two ranges
void quering_a_property2() {
	// equal -> checks if two collection have same elements in them and the
	// size of collection is same or not(returns bool)
	/** if you want to see i elements are equal, but not necessarily in same
	 * order, you can use "is_permutation(returns bool)" */

	// lexographical_compare -> it compares two collections in lexographical
	// order(just like say comparing a string, as "abcdefghij" is smaller than
	// "abcdxyz"), it returns bool for if first one is smaller than second one

	// mismatch -> compare two collection by traversing them both and stop at
	// the point whenever they start to differ(returns pair<iterator, iterator>
	// pointing to first mismatched element)
}


void searching_a_value() {
	/** when collection is not sorted */
	// find() -> takes begin and end of collection and value, returns the
	// iterator pointing to first position of value in the collection or end of
	// the container

	// adjacent_find() -> same parameter list as find(), but it returns the
	// first position where two adjacent value are equal to value given as
	// argument

	/** when collection is sorted */
	// equal_range -> returns a range(as in collection, there could be multiple
	// position with same value which we provided as argument and in sorted
	// collection they are going to be together and equal_range returns this
	// range of value)

	// lower_bound -> say the range provided by equal_range is "orange range",
	// lower_bound() indicates position to insert element if you were to insert
	// new orange element at the left of the existing orange range

	// upper_bound -> it'll be used to indicate position to insert element if
	// you were to insert new orange element at the right of the existing
	// orange range

	// binary_search -> returns boolean, takes begin, end and value and only
	// tells whether the value is there or not(but doesn't tells where)
}


void searching_a_range() {
	// search -> it searches a subrange(a collection which could or could not
	// be a part of bigger collection) into a range

	// find_end -> same as search, that means looking for the subrange in a
	// range but start searching from the end of range

	// find_first_of -> any of the element in subrange finding its first
	// appearance in bigger range
}


void searching_a_relative_value() {
	// max_element -> returns iterator pointing to max element in collection

	// min_element -> returns iterator pointing to min element in collection

	// minmax_element -> return pair<iterator, iterator> pointing to min and max element in collection
}



/*************************************
*  GLORIOUS COUNTY OF ALGOS ON SETS  *
*************************************/

void algos_on_sets() {
	/** In C++, a set is a sorted collection, so std::set is a set(which is a
	 * sorted collection), and so for this purpose, a sorted vector could also
	 * be considered as a set */

	// set_difference -> takes two sets and returns the elements that are
	// in first collection but not in second one, in linear
	// time-complexity(cause the inputs are sorted and also the output is
	// sorted too)
	/** std::set_difference(begin(A), end(A),
							begin(B), end(B),
							std::back_inserter(results)); */

	// set_intersection -> returns elements that are both in A and B

	// set_union -> returns the element that are both in A or B

	// set_symmetric_difference -> returns the elements that are in A and not
	// in B and elements that are in B and not in A

	// includes -> returns boolean, telling that whether all the elements of B
	// are also in A

	// merge -> takes two sorted collection and puts them together into a one
	// big sorted collection
}



/************************
*  TERRITORY OF MOVERS  *
************************/

void movers() {
	// copy(first, last, out) -> copies(performs std::copy() on every element
	// of collection to another collection) element from one collection to
	// another collection

	// move(first, last, out) -> same mentality as copy but performs
	// std::move() on every element(that means after performing this algorithm,
	// all the elements of input collection are moved)

	// swap_ranges(first, last, out) -> to swap the content of two ranges and
	// these ranges should be of same size

	// copy_backward -> start copying from backward of the input collection
	/** we can't use copy if the starting position of where to copy to as
	 * output comes under the range of what we want to copy, as in the same
	 * collection, element would be removed(copied over),
	 * e.g.,
	 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10  convert it to
	 * 1, 2, 3, 1, 2, 3, 4, 5, 9, 10
	 * if we use copy and as soon as copy '1' to position where '4' is, '4' is
	 * now not in the collection */

	// move_backward -> same as copy_backward but moves
}



/****************************
*  LAND OF VALUE MODIFIERS  *
****************************/


void value_modifiers() {
	// fill(first, last, value) -> puts the provided value in the given range

	// generate(first, last, func) -> call a function once with no
	// argument(func) for every element of the collection(every place on the
	// given range of collection)

	// iota(first, last, value) -> puts the value at first and increments the
	// value to fill every next place upto last

	// replace(first, last, v1, v2) -> replaces every v1 with v2 in the given range
}



/*********************************
*  island of structure changers  *
*********************************/

void changing_structure() {
	// remove(begin(A), end(A), value) -> used to remove values, but since STL
	// algorithms only access the iterators of the collection and not the
	// collection themselves, they can't change the size of
	// collection(performing erase etc.), all they can do is change value
	// withing begin() and end(). So, std::remove() pulls up the collection by
	// leaving only those, that should not be removed and returns the iterator
	// pointing to the first position just after the last element which should
	// not be removed and we can perform erase()(container specific operation)
	// on it
	/** collection.erase(std::remove(begin(A), end(A), value),
	 * end(collection)); */

	/** the above remove could be packaged as(this idea has been proposed): */
	// erase(collection, value) -> to remove the value from the collection

	// unique(begin(collection), end(collection)) -> remove the adjacent
	// duplicates and pulls up the values(which aren't going to be removed to
	// left) and returns iterator same as remove()
	/** {1, 2, 99, 99, 99, -1, -2, 99, 0, 1}  perfomring unique will change
	 * this into:
	 * {1, 2, 99, -1, -2, 99, 0, 1}
	 * collection.erase(std::unique(begin(A), end(A)), end(collection));
	 *
	 * same as remove(with erase), this should also be packages as
	 * "unique(collection)"
	 */

	/** *_copy -> algorithms which are going to in place of "*", they operate in
	* place, but new algorithms with *_copy will leave the collection
	* untouched and take output iterator and produce output to that output
	* iterator, they are:
	*
	* remove_copy
	* unique_copy
	* reverse_copy
	* rotate_copy
	* replace_copy
	* partition_copy
	* partial_sort_copy
	*/

	/** *_if -> these new formed algorithms takes predicate to satisfy the
	 * condition(several of these are used to do in place operation, like
	 * remove_if), they are:
	 *
	 * find_if
	 * find_if_not
	 * count_if
	 * remove_if
	 * remove_copy_if
	 * replace_if
	 * replace_copy_if
	 * copy_if
	 */
}



/*******************
*  LONELY ISLANDS  *
*******************/


void lonely_algos() {
	// transform -> it performs the provided function as arugment to every
	// element of the collection, you can also provide two collection and a
	// function with two parameters which when used with transform takes
	// element each time from both collection as its argument and perform
	// operation on it
	/** e.g.,
	 * std::transform(begin(A), end(A), std::back_inserter(B), func);
	 * std::transform(begin(A), end(A), begin(B), std::back_inserter(C), func);
	 * say, you want to have a new collection with the sum of elements of same
	 * index from two collection, we can do something like:
	 * std::transform(begin(A), end(A), begin(B), std::back_inserter(C), std::plus<int>()); */

	// for_each() -> performs a f(x) for every element x of collection, but
	// for_each() doesn't care of return value, so it could have
	// side_effects(this could be good and both, it depends)
	/** std::for_each(begin(collection), end(collection), f); */
}



/****************************
*  PENINSULA OF RAW MEMORY  *
****************************/


void raw_memory() {
	/** if we see std::fill(), std::copy() & std::move() algo, they have one
	 * thing is common, which is "="(assignment operator), like (simple
	 * assiginging value, calling copy assignment, calling move assignment). By
	 * using, assignment operator, we mean that object which is assigned has
	 * been constructed but if it's not(and we just got chunks of memory) and
	 * we would like to construct(call constructor) instead of assignment on
	 * those chunks of memory, for that we use "uninitialized_*" counterparts.
	 * So, for std::fill(), a constructor which takes the value, for
	 * std::copy(), a copy constructor and for std::move(), a move constructor
	 * e.g.,
	 * std::uninitialized_fill(begin(A), end(A), 42);  // 42 is used as value constructor
	 * */
	// uninitialized_fill
	// uninitialized_copy
	// uninitialized_move

	// destroy -> takes range, to call destructor

	// uninitialized_default_construct -> to call the default constructor

	// uninitialized_value_construct -> for initializing value construct
}


/** our final rune, "_n" */

void _n_runes() {
	/** instead of taking "begin() and end()", it takes "begin()" and "size".
	 * e.g.,
	 * std::fill(begin(A), end(A), 42);
	 * std::fill_n(begin(A), 5, 42); -> fills the first 5 element starting
	 * from begin and fills with 42
	 * std::fill_n(std::back_inserter(A), 5, 42); -> insert 5 elements equal to 42
	 * These *_n algos are:
	 copy_n
	 fill_n
	 generate_n
	 search_n
	 for_each_n
	 uninitialized_copy_n
	 uninitialized_move_n
	 uninitialized_fill_n
	 uninitialized_default_construct_n
	 uninitialized_value_construct_n
	 destroy_n */
}


/** There are few more algorithms in STL and much more outside(like Boost library) */

int main() {
	heap_func();
}
