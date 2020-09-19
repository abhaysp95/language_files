calcAge(1990);

// You see, cause the in this creation phase of global execution context,
// function declaration is already in the VO, so calling before also works

function calcAge(year) {
	console.log(2020 - year);
}

// up until now we have done this
// calcAge(1990);
// but we can also call it before the function


// Now, let's see how this works for function expression

// retirement(1990);
// You see this will give error, cause hoisting with function only works for
// function declaration

var retirement = function(year) {
	console.log(65 - (2020 - year));
}

// so, this has to be below the function expression
retirement(1990);


// Now, let's see hoisting for variables
console.log(age);  // this should give undefined
// In the creation phase of variable object, code is scanned for the variable
// declaration and the variables are then set to undefined(Question -> does it
// mean that the variable declaration we are looking for is already in the VO
// just like function declaration?)
var age = 56;
console.log(age);

console.log(newage);  // will give error
// cause we don't have any defination of the variable declaration in the VO
// that js knows of
var newage = 65;  // to check the the statement above comment this line

// lets see some more trick
function foo() {
	console.log(anotherAge);  // see, hoising for variable works here too
	var anotherAge = 59;
	console.log(anotherAge);
}
console.log(anotherAge);  // this will still give undefined
var anotherAge = 23;
foo();
console.log(anotherAge);  // now this will give 23, cause both anotherAge of
// global execution context and foo() have their sepeare VO
