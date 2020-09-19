// creating a basic function constructor(blue print)

var Person = function(name, yearOfBirth, job) {
	this.name = name;
	this.yearOfBirth = yearOfBirth;
	this.job = job;
	// just normal, adding a method to the object
	/*this.calcAge = function() {
		return 2020 - this.yearOfBirth;
	}*/
}

var john = new Person("John", 1989, "Teacher");
// now john is the instance of Person and the process is called instantiation

// due to new object, 'this' doesn't point to global but instead 'new' first creates an empty object and then 'this' points to that object

//console.log(john.calcAge());
// also for calcAge, that method is just simply attached to these three objects, but let's use inheritance

Person.prototype.calcAge = function() {
	return 2020 - this.yearOfBirth;
}
// now calcAge is not attached the objects created via Person, but they will have access to the calcAge(above) because it's in the prototype of Person

// just like method inheritance could also be done for a property with the help of prototype property
Person.prototype.lastName = "Smith";

var jane = new Person("Jane", 1969, "Retired");
var mark = new Person("Mark", 1982, "Designer");

console.log(john.calcAge());
console.log(jane.calcAge());
console.log(mark.calcAge());


// so currently all of three are having 'calcAge'

console.log(john.lastName);
console.log(jane.lastName);
console.log(mark.lastName);

// the prototype of John is the prototype property of the function constructor
console.log(john.__proto__ == Person.prototype);

// this is accessing the Object's prototype property cause every object is inheriting the Object
console.log(john.hasOwnProperty("job"));  // -> true
console.log(john.hasOwnProperty("calcAge"));  // -> false, becuase calcAge is inherited and it's not the method of Person class itself
//console.log(john instanceOf Person);

let arr = [1, 2, 3];
console.info(arr);
// inspecting the info result, we see that 'length' is an property of Array Object and there are several prototypes like push, pop for Array
