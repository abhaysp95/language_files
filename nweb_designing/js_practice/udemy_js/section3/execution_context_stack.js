// every js code is parsed through a parser, some kind of js engine, in which code goes through AST and gets changed to object code/byte code and then that is executed

// There's a concept of execution context and execution stack

/* Everything globally in the js code is part of global execution context,
 * which is just the property of window object(or is window object). */
/* So, thisname === windows.thisname;  is same thing. As we know, properties
 * are the variables attatched with the object. Global part */

var name = 'John';

function first() {
	let a = 'Hello';
	console.log(a + ' ' + name);
	second();
}

function second() {
	let b = 'Hii';
	console.log(b + ' ' + name);
	third();
}

function third() {
	let c = 'Hey';
	console.log(c + ' ' + name);
}

first();


/* var name = 'John'; and first(); are in global execution context. Not the code inside the functions, so hierachy is like global execution stack, like this */

/* Following the rule of stack(LIFO) */
/* global -> first() -> second() -> third() */



/*  Execution Context Object  */

/* Basically, the element of stack, Execution Context Object consist of ->
   1. Variable Object(VO)
   2. Scope Chain
   3. 'This' variable
*/

/* This Execution Context Object has two phase -
	1. Creation Phase
		- Creation of VO
		- Creation of Scope Chain
		- Determining the value of 'This'

	2. Execution Phase
		- The code of the function that generated the current execution context is run line by line
*/

/* Now let's see what is VO and what happens in it in Creation Phase

- The argument object is created, containg all the arguments that were passed into the funciton
- Code is scanned for 'functions declaration': for each function, a property is created in the Varible Object, pointing to the function.
    This means that all the functions will be stored in execution object even before the code starts executing.
- The code is scanned for variable declarations: for each variable property is created in VO, and set to undefined.

The las to points is known as `Hoisting`. Which means `functions and variables`(which is hoisted in js) are actually available before the execution phase. 'Functions' are actually defined while variable are undefined at this phase */
