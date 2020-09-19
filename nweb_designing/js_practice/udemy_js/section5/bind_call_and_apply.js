var john = {
	name: "John",
	age: 28,
	job: "teacher",
	presentation: function(style, timeOfDay) {
		if (style === "formal") {
			console.log("Hello, Good " + timeOfDay + "! " +
			"My name is " + this.name +
			"I'm " + this.age + " years old and I'm a " + this.job);
		}
		else if (style === "informal") {
			console.log("Hey, Good " + timeOfDay + "! " +
			"How are you guys? " +
			"My name is " + this.name +
			"I'm " + this.age + " years old and I'm a " + this.job);
		}
	}
};

john.presentation("formal", "Morining");

var emily = {
	name: "Emily",
	age: 25,
	job: "designer"
};

console.log("------------------------------------------");

// now this is one of using property of one object and create new property with it to another object
/*emily.presentation = john.presentation;
emily.presentation("informal", "AfterNoon");
console.log(emily);*/  // also this attaches one more property but if you don't want to do so, see below

// but let's use "method borrowing"
john.presentation.call(emily, "informal", "AfterNooon");
console.log(emily);  // it doesn't have "presentation" property attached to "emily" object
// first arg, sets "this" for john to "emily" instead of "john" in "john" object and rest are the required usual parameters


// now there's another method "apply" which can be used in place of "call", but it only takes two args, first "this" one and second is array
john.presentation.apply(emily, ["informal", "Evening"]);  // now, this shouldn't work because our "presentation" method doesn't takes array as input but it's working. How?
console.log(emily);  // still doesn't attaches property method "presentation"


// bind method will return the function
var johnInformal = john.presentation.bind(john, "informal");
johnInformal("Night");
// this process is called currying(basically means instead of taking multiple
// args with same function, taking partial arguments with the sequence of
// function)
var emilyFormal = john.presentation.bind(emily, "formal");
emilyFormal("Morning");

console.log("------------------------------------------");

// let's take example from previous of performing operation on ages
let years = [ 1990, 1995, 2000, 2005, 2010, 2015 ];

function arrayCalc(arr, fn) {
	let newArr = [];
	for (let element of arr) {
		newArr.push(fn(element));
	}
	return newArr;
}

function calcAge(el) {
	return 2020 - el;
}

// limit means fullAge can be different for different countries
function isFullAge(limit, el) {
	return el >= limit;
}

let ages = arrayCalc(years, calcAge);
console.log(ages);
let fullAgeJapan = arrayCalc(ages, isFullAge.bind(this, 20));
// can also use none in place of this
//If no arguments are provided to bind , or if the thisArg  is null or undefined, the this of the executing scope is treated as the thisArg for the new function.
console.log(fullAgeJapan);
let fullAgeIndia = arrayCalc(ages, isFullAge.bind(this, 18));
console.log(fullAgeIndia);
// as you can see from above, "isFullAge.bind()" is returning a function requiring partial argument, and "this" is used as first arg, because the function is in global context and there's simply not else to pass -W-

/* One can thing to provide the default value to "limit" in "isFullAge" but that will not serve the purpose */


console.log("------------------------------------------");


// Some other examples of currying(bind())

const nmodule = {
	x: 42,
	getX: function() {
		return this.x;
	}
};

console.log(nmodule.getX());
const unboundedGetX = nmodule.getX;  // The function gets invoked at global scope
console.log(unboundedGetX());

const boundedGetX = unboundedGetX.bind(nmodule);  // provided value for "this" as nmodule
console.log(boundedGetX());
/* Description: The bind() function creates a new "bound
 * function", which is an exotic function object that wraps the
 * original function object. Calling the bound function
 * generally results in the execution of its wrapped function
 * */

console.log("------------------------------------------");

// another example
//A common mistake for new JavaScript programmers is to extract a method from an object, then to later call that function and expect it to use the original object as its this (e.g., by using the method in callback-based code).

//Without special care, however, the original object is usually lost. Creating a bound function from the function, using the original object, neatly solves this problem:

this.x = 9;  // "this" refers to global 'window' object here in a browser
const smodule = {
	x: 81,
	getX: function() {
		return this.x;
	}
}

smodule.getX();  // returns 81(just like in previous example where it was undefined)
// mistake -> extracting a method from an object then to later call that function, but this for original object "smodule" is now lost
const retrieveX = smodule.getX;  // as the function gets invoked in global scope
retrieveX();
const nboundGetX = retrieveX.bind(smodule);
console.log(nboundGetX());

console.log("------------------------------------------");

// one more example
function list() {
	// what I am understanding with this line(below) -> Array object have "slice" method in prototype that means "slice" can be inherited and then "method borrowing" for arguments(or what I think to another object)
	return Array.prototype.slice.call(arguments);
}

function addArguments(arg1, arg2) {
	return arg1 + arg2;
}

const list1 = list(1, 2, 3);  // question -> how is list() taking argument "1, 2, 3", shouldn't list() be declared as list(...args) to take any number of arguments
console.log(list1);
const result1 = addArguments(1, 2);
console.log(result1);
const leadindThirtySevenList = list.bind(null, 37);
const addThirtySeven = addArguments.bind(null, 37);
const list2 = leadindThirtySevenList();
list3 = leadindThirtySevenList(1, 2, 3);  // providing partial arguments
console.log(list3);
const result2 = addThirtySeven(5);
console.log(result2);
const result3 = addThirtySeven(10, 20);  // second argument is ignored
console.log(result3);
