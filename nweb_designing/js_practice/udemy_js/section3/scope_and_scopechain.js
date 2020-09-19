// unlike other languages where you can have different scope for variables with if, for block etc. js only have different scope for variables with function

/* There's also lexical scoping in js -> a function which is lexically within another function gets access to the scope of outer(parent) function */

// let's see a example

var a = 'Hii';
first();

function first() {
	var b = 'Hello';
	second();
	function second() {
		var c = 'Hey';
		console.log(a + b + c);
	}
}

/* the whole code comes under global scope(default scope). Body of first() is 'first() scope' which have VO1 and VO(global) and body of second() is 'second() scope' which have VO2 + VO1 + VO(global). That's due to lexical property */
/* Each scope have it's execution context object */

// Execution stack is the order in which function are called and scope chain is the order in which functions are written in the code

var a = 'Hii';
first();

function first() {
	var b = 'Hello';
	second();
	function second() {
		var c = 'Hey';
		third();
	}
}

function third() {
	var d = 'John';
	console.log(a + b + c + d);
}

/* Now execution stack will be like
global -> first() -> second() -> third()

but scope chain will be like
global -> first() -> second()
  |
  ---> third() */

// so, third() can't access var b and c

/* so, even though second() function is calling third() due to scope chain cause third() is in global scope lexically, third() can't access b or c due to because they are in different scope than third() */
