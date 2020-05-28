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

// Object.freeze(MATH_CONSTANTS.PI);  this will only prevent PI mutation,
// to prevent full object give only obejct name
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


// wrapped curly brackets in parentheses to avoid it being considered of
// wrapping function body brackets
const myFunction = () => ({value: 'test'})
console.log(myFunction());


const DOUBLE = x => {x * 2};
console.log(DOUBLE(3));


// high oreder arrow functions
const realNumberArray = [4, 5.6, -9.8, 3.14, 42, 6, 8.34, -2];

// if there's only one argument for arrow function, no need to use () around it
const SQUARELIST = arr => {
	// method name is Number
	const SQAUREDINT = arr
		.filter(num => Number
		.isInteger(num) && num > 0)
		.map(x => x * x);
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
/*const sum = (() => {
	return function Sum(x, y, z) {
		const args = [x, y, z];
		return args.reduce((a, b) => a + b, 0);
	};
})();*/

/*const sum = (() => {
	return function sum(...args) {
		return args.reduce((a, b) => a + b, 0);
	}
})();*/
// or we could write like this
const sum = (...args) => args.reduce((a, b) => a + b, 0);
console.log(sum(1, 2, 3, 4));


// spread operator to evaluate array in place
// it takes an array and spreads out into its individual parts
let arr1 = ['Jan', 'Feb', 'March', 'Apr', 'May', 'Jun'];
let arr2;
(() => {
	// this is basically like pointer in C, to references pointing to a array
	// so changing elements of arr1 also changes arr2
	arr2 = arr1;
	arr1[0] = 'potato';
})();
console.log(arr2);


let arr3 = ['Jan', 'Feb', 'March', 'Apr', 'May', 'Jun'];
let arr4;
(() => {
	arr4 = [...arr3]; // spread operator
	arr3[0] = 'tomato';
})();
console.log(arr4);


// destructuring assignment to assign variables from object
let voxel = {
	'x': 3.6,
	'y': 7.4,
	'z': 6.54
}
// assign these to their own named variables
let x = voxel.x;
let y = voxel.y;
let z = voxel.z;
console.log(x, y, z);

const {
	x: a,  // a = 3.6
	y: b,  // b = 7.4  c = 6.54
	z: c
} = voxel;
console.log(a, b, c);

// average temperature
const AVG_TEMPERATURE = {
	'today': 77.5,
	'tomorrow': 79
}

function getTempOfTmrw(avgTemperature) {
	"use strict"
	const {
		// today: tempOfToday,  this isn't necessary
		tomorrow: tempOfTomorrow
	} = avgTemperature;
	return tempOfTomorrow;
}
console.log(getTempOfTmrw(AVG_TEMPERATURE));


// destructuring assignment with nested objects

const LOCAL_FORECAST = {
	today: {
		min: 72,
		max: 83
	},
	tomorrow: {
		min: 73.3,
		max: 84.6
	}
};

function getMaxOfTmrw(forecast) {
	"use strict";
	const {
		tomorrow: { max: maxOfTomorrow}
	} = forecast;
	return maxOfTomorrow;
}
console.log(getMaxOfTmrw(LOCAL_FORECAST));

// testing
function getMaxOfTmrw2(forecast) {
	"use strict";
	const {
		max: maxOfTomorrow
	} = forecast;
	return maxOfTomorrow;
}
console.log(getMaxOfTmrw2(LOCAL_FORECAST.tomorrow));


// use destructuring assignment to assign variables from arrays
// till now we were doing it with objects
let [p, q] = [1, 2, 3, 4];
console.log(p, q);  // this will give in serial

let [r, , , s, , t] = [1, 2, 3, 4, 5, 6, 7];
console.log(r, s, t);

// switching places
let g = 8, h = 6;
(() => {
	"use strict";
	[g, h] = [h, g];
})();
console.log(g);
console.log(h);


// use destructuring assignment with rest operator
const SOURCE = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
function removeFirstTwo(list) {
	// const [ , , arr] = [...list]; this will give arr = 3
	// const [ , , ...arr] = [...list];
	const [ , , ...arr] = list;  // same as above
	return arr;
}
const arr = removeFirstTwo(SOURCE);
console.log(arr);
console.log(SOURCE);


// use destructuring assignment to pass an object as a function's paraemter

// normal
const stats = {
	max: 56.78,
	standard_deviation: 4.34,
	median: 34.54,
	mode: 23.87,
	min: -0.75,
	average: 35.85
}
const half = (() => {
	return function half(stats) {
		return (stats.max + stats.min) / 2.0;
	};
})();
console.log(stats);
console.log(half(stats));

// with destructuring
const half2 = (() => {
	// stats is destructured just in max and min
	return function half( {max, min} ) {
		return (max + min) / 2.0;
	};
})();
console.log(half(stats));

// creating string using template literals
// benifits -> multiline strings
// no escaping ' and "
// direct use of variables
const person = {
	name: "Zodiac Hasbro",
	age: 56
};
const greeting = `Hello, my name is ${person.name}!
I am ${person.age} years old.`
console.log(greeting);


// a problem
const result = {
	success: ["max-length", "no-and", "prefer-arrow-functions"],
	failure: ["no-var", "var-on-top", "linebreak"],
	skipped: ["id-blacklist", "no-dup-key"]
};
function makeList(arr) {
	const resultDisplayArr = [];
	for (let i = 0; i < arr.length; i++) {
		resultDisplayArr.push(
			`<li class="text-warning">${arr[i]}</li>`
		);
	};
	return resultDisplayArr;
};
console.log(makeList(result.failure));


// concise object literal declarations using simple fields
// normal
const createPerson = (name, age, gender) => {
	return {
		"name": name,
		"age": age,
		"gender": gender
	};
};
console.log(createPerson("Zodiac Hasbro", 56, "male"))
// concise form
const createPerson2 = (name, age, gender) => ( {name, age, gender} );
console.log(createPerson2("Zodiac Hasbro", 56, "male"))


// concise declarative functions
const bicycle = {
	gear: 2,
	// long way
	/*setGear: function(newGear) {
		// this function may be converted to class declaration
		"use strict";
		this.gear = newGear;
	}*/
	// short way
	setGear(newGear) {
		"use strict";
		this.gear = newGear;
	}
};
bicycle.setGear(3);
console.log(bicycle.gear);


// class syntax to define a constructor function
// old way
var spaceShuttle = function(targetPlanet) {
	this.targetPlanet = targetPlanet;
}
// instantiating the object(spaceShuttle) with new keyword
var zeus = new spaceShuttle('Jupiter')
console.log(zeus.targetPlanet);

// the class syntax replaces the constructor function creation
class spaceShuttle2 {
	constructor(targetPlanet) {
		this.targetPlanet = targetPlanet;
	};
};
var zeus = new spaceShuttle2('Jupiter')
console.log(zeus.targetPlanet);

// practice
function makeClass() {
	class Vegetable {
		constructor(name) {
			this.name = name;
		}
	}
	return Vegetable;
}
const Vegetable = makeClass();
const carrot = new Vegetable('carrot');
console.log(carrot.name);


// getters and setters to control access to an object
// getters -> getter functions are used to simply return private variable
// of an object to the user, without the user's directly accessing the private variable
// same with the setting
// example
class Book {
	constructor(author) {
		// _author is private variable
		this._author = author;
	}
	// getter
	get writer() {
		return this._author;
	}
	set writer(updatedAuthor) {
		this._author = updatedAuthor;
	}
}
const authorIs = new Book('R. R. Martin');
authorIs.writer = 'J. K. Rowlings';
console.log(authorIs.writer);

// thermostat
function makeClass() {
	class Thermostat {
		// it's in fehrenheit
		constructor(temp) {
			this._temp = 5 / 9 * (temp - 32);
		}
		get temperature() {
			return this._temp;
		}
		set temperature(updatedTemp) {
			this._temp = updatedTemp;
		}
	}
	return Thermostat;
}

const getTemp = makeClass();
const thermos = new getTemp(76);
// getters and setters are similar to properties
// so, no () after it
let temp = thermos.temperature;
thermos.temperature = 26;
console.log(temp);
console.log(thermos.temperature);


// import export
export const capitalizedString = str => str.toUpperCase();
