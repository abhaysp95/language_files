// another way of creating object in javascript

// Object.create

// First we'll build prototype and then object upon that prototype

var personProto = {
	calcAge: function() {
		return 2020 - this.yearOfBirth;
	}
}

var john = Object.create(personProto);
// now let's give john some property
john.name = "John";
john.yearOfBirth = 1998;
john.job = "Teacher";

// Another way of filling
// we can give an object as a parameter to make them property of the object we are creating
var jane = Object.create(personProto, {
	name: { value: "Jane" },
	yearOfBirth: { value: 1989 },
	job: { value: "Designer" }
})
