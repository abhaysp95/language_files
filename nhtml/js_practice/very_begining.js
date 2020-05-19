var myName = "Abhay"  // global
myName = "abhay"
let ourName = "linux"  // only in scope
const pi = 3.14  // should and can never change

var a;  // declaration
var b = 2;  // declaration and initialization
console.log(a);
a = 7;
b = a;
console.log(a);

var StUdy;  // variables in js are case-sensitive
stuDy = 10;
// use camelcase for variable names

var result = 10 + 10;
console.log(result);

var product = 2.0 * 2.5;
console.log(product);

var myStr = "FirstLine\n\t\\SecondLine\nThirdLine"
console.log(myStr);

adjective = 'good';
sentence = 'He is ';
sentence += adjective;
console.log(sentence);
console.log('Length of sentence is: ' + sentence.length);
console.log('2nd letter is: ', sentence[1]);
sentence[1] = 'd';  // this will not change character
// strings are immutable
console.log('2nd letter is: ', sentence[1]);
console.log('Last letter of sentence: ' + sentence[sentence.length - 1]);

function wordBlanks(noun, adjective, verb, adverb) {
	var result = "";
	result += 'The ' + adjective + ' ' + noun + ' ' + verb + ' to the store ' + adverb;
	return result;
}
console.log(wordBlanks('dog', 'big', 'ran', 'quickly'));
console.log(result);  // this is global

// arrays
var ourArray = ["Stimpson", "J", "cat"];
ourArray.push(["happy", "joy"]);
console.log(ourArray);
var myArray = [["john", 23], ["cat", 2]];
myArray.push(['dog', 3]); myArray[2].push(['aword']);
console.log(myArray);
console.log('Removed element with pop(): ' + ourArray.pop());  // removes last
console.log('Removed element with pop(): ' + myArray[1].pop());
console.log('Removed element with shift(): ' + myArray[1].shift());  // removes begining
myArray[1].unshift(["lion", 3]);
console.log(myArray);

// global, local scope and functions
var myGlobal = 10;

function fun1() {
	// if var is not given here, it'll automatic be global
	// if var given it'll be limited to this function's scope onely
	oopsGlobal = 5;
}
function fun2() {
	var output = "";
	if (typeof myGlobal != "undefined") {
		output += "myGlobal: " + myGlobal;
	}
	if (typeof oopsGlobal != "undefined") {
		output += " oopsGlobal: " + oopsGlobal;
	}
	console.log(output);
}

fun1();
fun2();

var outerWear = 'T-Shirt';
// precedence of local variable is more than global variable
function myOutfit() {
	var outerWear = "sweater";
	console.log('Scope inside function: ' + outerWear);
	// return outerWear;
}
// console.log(myOutfit());
myOutfit();
console.log('Scope outside function: ' + outerWear);

// simulation of queue
function nextInLine(arr, item) {
	arr.push(item);
	return arr.shift();
}
var testArr = [1, 2, 3, 4, 5];

console.log("Before: ", JSON.stringify(testArr));
console.log(nextInLine(testArr, 6));
console.log("After: ", JSON.stringify(testArr));
console.log("type is: " + typeof JSON.stringify(testArr));


// boolean in js
function welcomeToBooleans() {
	return true;
}


// if-else in js
function trueOrFalse(wasThatTrue) {
	if (wasThatTrue) {
		return "yes, that was true";
	}
	return "no, that was false";
}
console.log(trueOrFalse(true));

// == attempts to convert both values being compared to same type
// === doesn't convert

function testStrict(val) {
	if (val === 3) {
		return "First Equal";
	}
	else if (val === '3') {
		return "Second Equal";
	}
	return "not equal";
}
console.log(testStrict('3'));

function compareEquality(a, b) {
	if (a == b) {  // converts string into int
		return "Equal";
	}
	return "Not Equal";
}
console.log(compareEquality(10, "10"));

function compareStrictEquality(a, b) {
	if (a === b) {  // no conversion, checking if int == string
		return "Equal";
	}
	return "Not Equal";
}
console.log(compareStrictEquality(10, "10"));
// != inequality, does type-conversion
// !== strict-inequality, no type-conversion


// comparision operation
function testLogical(val) {
	if (20 <= val <= 50) {
		return "It's true";
	}
	return "It's False";
}
console.log(testLogical(35));


// Golf Code
var names = ["Hole-in-one", "Eagle", "Birdie", "Par", "Bogey", "Double Bogey", "Go Home"];
function golfScore(par, strokes) {
	if (strokes == 1) {
		return names[0];
	}
	else if (strokes <= par - 2) {
		return names[1];
	}
	else if (strokes == par - 1) {
		return names[2];
	}
	else if (strokes == par) {
		return names[3];
	}
	else if (strokes == par + 1) {
		// return names[-3];  this type of slicing doesn't work in js
		return names[names.length - 3];
	}
	else if (strokes == par + 2) {
		return names[names.length - 2];
	}
	else if (strokes >= par + 3) {
		return names[names.length - 1];
	}
}
console.log(golfScore(4, 5));


// switch statement
function caseInSwitch(val) {
	var answer="";
	switch(val) {
		case 1:
			answer = "alpha"; break;
		case 2:
			answer = "beta";
			break;
		case 3:
			answer = "gamma";
			break;
		case 4:
			answer = "delta";
			break;
		default:
			answer = "not given right value";
	}
	return answer;
}
console.log(caseInSwitch(1));
