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

function myOutfit() {
	var outerWear = "sweater";
	console.log('Scope inside function: ' + outerWear);
	// return outerWear;
}
// console.log(myOutfit());
myOutfit();
console.log('Scope outside function: ' + outerWear);
