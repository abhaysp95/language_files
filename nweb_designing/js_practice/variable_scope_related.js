// let doesn't let you declare a varible twice
var catName = "Quincy";
var quote;

var catName = "Beau";
// let catName = "Meow";  // duplicate declaration
catName = "Tom";

function catTalk() {
	"use strict";  // you can also give this at starting of document
	catName = "Oliver";
	// let catName = "Thomas";  duplicate
	quote = catName + " says Meow!";
}
catTalk();

function checkScope() {
	"use strict";
	let i = "function scope";
	if (true) {
		let i = "block scope";
		console.log("Block scope is: ", i);
	}
	console.log("Function scope is: ", i);
	return i;
}
console.log(checkScope());
// console.log(i);  not defined, cause we use let in function not var


// const has all the features of let but it's read-only
function printManyTimes(str) {
	"use strict";

	const SENTENCE = str + " is cool";

	for (let i = 0; i < str.length; i+=2) {
		console.log(SENTENCE);
	}
	// console.log(i);  outside scope
}
// console.log(i);  outside function
printManyTimes("JavaScript");


// mutate a const arr
const ARR = [5, 7, 2];
function editInPlace() {
	"use strict";
	// ARR = [2, 5, 7];  invalid assignment to CONST
	ARR[0] = 2;
	ARR[1] = 5;
	ARR[2] = 7;
}
editInPlace();
console.log(ARR);
// object and array can be mutated even if they are declared by const


// freeze object from mutation
function freezeObj() {
	"use strict";
	const MATH_CONSTANTS = {
		PI: 3.14,
		G: 9.8
	};

// Object.freeze(MATH_CONSTANTS.PI);  this will only prevent PI mutation, to prevent full object give only obejct name
Object.freeze(MATH_CONSTANTS);

	try {
		MATH_CONSTANTS.G = 99;
	}
	catch (ex) {
		console.log(ex);
	}
	return MATH_CONSTANTS.G;
}
const G = freezeObj();
console.log(G);


// anonymous function
/*var magic = functiion() {
	return new Date();
};*/
// can be written as

var magic = () => {
	return new Date();
}
// if returning only one value we can write as
const MAGIC = () => new Date();
console.log(MAGIC);

// another example
var myConcat = function(arr1, arr2) {
	return arr1.concat(arr2);
}
const myConcat2 = (arr1, arr2) => arr1.concat(arr2);
console.log(myConcat2([12, 43], [34, 902, 932]));


// wrapped curly brackets in parentheses to avoid it being considered of wrapping function body brackets
const myFunction = () => ({value: 'test'})
console.log(myFunction());


const DOUBLE = x => {x * 2};
console.log(DOUBLE(3));


// high oreder arrow functions
const realNumberArray = [4, 5.6, -9.8, 3.14, 42, 6, 8.34, -2];

// if there's only one argument for arrow function, no need to use () around it
const SQUARELIST = arr => {
	// method name is Number
	const SQAUREDINT = arr.filter(num => Number.isInteger(num) && num > 0).map(x => x * x);
	return SQAUREDINT;
};
// console.log(SQUARELIST(realNumberArray));
const SQUAREDINTEGERS = SQUARELIST(realNumberArray);
console.log(SQUAREDINTEGERS);


//high order arrow function
const INCREMENT = (() => {
	return function increment(number, value = 1) {
		return number + value;
	};
})();
//const INCREMENT = function() {
	//return function increment(number, value = 1) {
		//return number + value;
	//}
//}();
console.log(INCREMENT(5, 2));
console.log(INCREMENT(5));


// rest operator with function parameter
