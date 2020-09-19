/* functions are instace of object type
A function behaves like any other object, we can store function in variable, use function in parameter or return the function from a function */

// First Class Function

var years = [ 1970, 1980, 1990, 2000, 2010 ];

function arrayCalc (arr, fn) {
	let newArr = [];
	for (let ele of arr) {
		newArr.push(fn(ele));
	}
	return newArr;
}

/*console.log(arrayCalc(years, function(el) {
	return 2020 - el;
}));*/
function calcAge(el) {
	return 2020 - el;
}

function isFullAge(el) {
	return el >= 18;
}

var ages = arrayCalc(years, calcAge);
console.log(arrayCalc(years, calcAge));
console.log(arrayCalc(arrayCalc(years, calcAge), isFullAge));
console.log(arrayCalc(ages, isFullAge));
console.log(arrayCalc(ages, function(el) {
	if (el >= 18 && el < 82) {
		return Math.round((206.9 - (0.67 * el)) * 1000 ) / 1000;
	}
	return -1;
}));


// let's now take a look at how to return function

// generic function
function interviewQuestion(job) {
	if (job === "teacher") {
		return function(name) {
			return "Hello " + name + ", what do you teach?";
		}
	}
	else if (job == "designer") {
		return function(name) {
			return "Tell me " + name + ", what's your best design?";
		}
	}
	else {
		return function(name) {
			return "Hello " + name + ", what do you do?";
		}
	}
}

let teacherQ = interviewQuestion("teacher");
console.log(teacherQ("Jake"));
// another way of calling
console.log(interviewQuestion("designer")("John"));
