/* function that operate on other functions, either by taking argument or returning them.
High order function allows abstraction over actions, not just values. They come in several forms. */

// Example

//import { repeat } from "./abstracting_repeatition.js"
//const abs_rep = require("./abstracting_repeatition");
// or
const { repeat, labels } = require("./abstracting_repeatition");

function greaterThan(n) {
	return m => m > n;
}

// just the previous version of function but not es6+
function grtrThan(n) {
	return function(m) {
		return m > n;
	}
}

let greaterThan10 = greaterThan(10);
let grtrThan10 = grtrThan(10);

console.log(greaterThan10(20));
console.log(grtrThan10(8));


// We can have function that changes another function

function noisy(func) {
	return (...args) => {
		console.log("calling with ", args);
		let result = func(...args);
		console.log("called with ", args, ", returned ", result);
		return result
	}
}

console.log("------------------------------");
let noisyfunc = noisy(Math.min);
console.log(noisyfunc(3, 2, 1));
console.log("------------------------------");
// or we can call as
noisy(Math.max)(4, 9, 29, 19, 15);
console.log("------------------------------");
// this is also returning result, just like "console.log(noisyfunc(3, 2, 1));"
let result = noisy(Math.max)(394, 29, 92, 9293, 910);
console.log(result);


// We can even write functions that provide new types of control flow
function unless(test, then) {
	if (!test) {
		then();
	}
}

// remember this is not definition of function, this is the calling of function
repeat(3, n => {
	unless (n % 2 == 1, () => {
		console.log(n, " is even");
	});
});
