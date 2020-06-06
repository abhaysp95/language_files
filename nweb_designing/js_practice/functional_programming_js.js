// tfrying funtional programming in JS

// these are the limitations to apply in js to understand pure functional programming
// these are not the limitations of functional programming

// 1. No loops, use recursion
// 2. No. Ifs(except ternary operator)
// 3. Function should only containg single return and nothing else
// 4. No side-effects(no printing on console) -> you can make program in two parts now,
// functional -> no sid-effects and non-functional -> side-effects(which is real-short)
// 5. No assignments inside function(mostly if assigning global inside function but don't use any kind)
// 6. No arrays(can use objects)
// 7. Every function can have only zero or one arguments


// ex. of 1, 2 & 3
function sum(i) {
	return i <= 0 ? 0 : i + sum(i - 1)
}
// more functional
let tsum = (x) => x <= 0 ? 0 : x + tsum(x - 1)


// ex. of 7
function sum7(a, b) {
	return a + b;
}
// can be written as
function nsum7(a) {
	return function(b) {
		return a + b;
	}
}
nsum7 (5) (4)
// even better
let nnsum7 = (a) => (b) => a + b;


// ex. of 6, use functional lists(just a chain of pair)
// construction of pairs
let pair = first => second => {
	return {
		first: first,
		second: second
	};
}
pair (10) (20)
// returning first element of pair
let fst = (p) => p.first
fst (pair (10) (20))
// returning second element of pair
let snd = (p) => p.second
snd (pair (10) (20))

// we'll denote empty list with null
pair (10) (null)  // list with single element
pair (20) (pair (10) (null))  // list with two elements
let xs = pair (30) (pair (20) (pair (10) (null)))  // list with three elements
fst (xs)  // head of the list
snd (xs)  // tail of the list

// making semantic a bit better
let head = fst
let tail = snd
head (xs)  // 30
tail (xs)  // rest of the list from 20
tail (tail (xs))  // from 10 to null
head (tail (xs))  // 20
head (tail (tail (xs)))  // 10

// breach between functional world and imperative world to inspec result
function list2array(xs) {
	let result = [];

	while (xs != null) {
		result.push(head (xs));
		xs = tail (xs);
	}
	return result;
}
list2array(xs);

// lets try opposite approach
// make make array to functional list
function array2list(arrayLike) {
	let result = null;
	let xs = Array.from(arrayLike).reverse();
	// or else array would be created in reverse order
	for (let i = 0; i < xs.length; i++) {
		result = pair (xs[i]) (result);
	}
	return result;
}
array2list([100, 200, 300]);
array2list("Hello");

// try
array2list(list2array(xs));


// Fizz-Buzz problem
// Print numbers from 1 to 100 but if divisble by 3 print 'Fizz', if by 5 print
// 'Buzz', if divisble by both 'FizzBuzz'

// let's try imperative approach

function fizzBuzz2() {
	let num_range = [];
	for (let i = 1; i <= 100; i++) {
		if (i % 15 == 0) {
			num_range.push('FizzBuzz');
		}
		else if (i % 5 == 0) {
			num_range.push('Buzz');
		}
		else if (i % 3 == 0) {
			num_range.push('Fizz');
		}
		else {
			num_range.push(i);
		}
	}
	return num_range;
}
let num_array = fizzBuzz2();


// let's try functional approach
// function to give numbers in certain range
let range = (low) => (high) => {
	low > high
		? null
		: pair (low) (range (low + 1) (high))
}
