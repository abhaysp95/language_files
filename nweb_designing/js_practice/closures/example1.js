let myName = 'My Name'

function printName() {
	console.log(myName);
}

myName = 'Your Name'

printName()  // will print 'Your Name'

myName = 'His Name'

printName()  // will print 'His Name'

/* This entire thing above is one giant closure, we accessing myName(ext. variable) inside function printName()

Our entire js file is one scope then function printName() is another scope, every scope has access to everything outside the scope */


// another example

function outerFunction(outerVariable) {
	const outer2 = 'Hi'
	return function innerFunction(innerVariable) {
		console.log('Outer Variable: ' + outerVariable);
		console.log('Inner Variable: ' + innerVariable);
		console.log(outer2);
	}
}

const newFunction = outerFunction('outside')
newFunction('inside');

/* innerFunction() is still keeping track of outerVariable and by that way it
* can be used later even if the outerFunction is finished executing and
* those variables are no longer accessible, so everything in outerFunction
* is in innnerFunction() */


// another example

//function anotherOuter(url) {
	//fetch('url').then(() => {
		//console.log(url);
	//})
//}

//const anotherNewFunction = anotherOuter('url')
//anotherNewFunction();

// another example

function addwith(fnum) {
	return (snum) => {
		return fnum + snum;
	}
}

let addwith3 = addwith(3);
console.log(addwith3(5));