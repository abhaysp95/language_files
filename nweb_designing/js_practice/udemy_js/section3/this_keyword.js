/* Usage of 'this' keyword

- Regular function call: the 'this' points at the global object,(the window object in the browser)
- Method call: the 'this' variable points to the object that is calling the method.
- The 'this' keyword is not assigned a value until a function where it is defined is actually called */

// It's because we know that 'this' keyword is attached to the execution context which is only created as soon as function is invoked(called)

console.log(this);

calcAge(1999);

// a regual function call, object that this function is attached is windows(global)
function calcAge(year) {
	console.log(2020 - year);
	console.log(this);
}

// lets check method
var john = {
	name: 'John',
	birthYear: 1990,
	calcAge: function() {
		console.log(2020 - this.birthYear);
		console.log(this);

		innerFunction();
		// regular function call
		function innerFunction() {
			console.log('innerFunction');
			console.log(this);
		// now this function's 'this' will be global object(as per the rule)
		}
	}
}

john.calcAge();


// lets see the 3rd rule
var mike = {
	name: 'Mike',
	birthYear: 1984
}
// instead of writing calcAge again for Mike(treating function as variable)
mike.calcAge = john.calcAge;
mike.calcAge();
// so, 'this' keyword is only assigned the value when object calls the method
