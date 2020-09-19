// objects and methods

var john = {
	firstName: 'John',
	lastName: 'Smith',
	birthYear: 1999,
	family: {
		wife: 'Jane',
		sons: ['Mark', 'Bob'],
		daughter: 'Emily'
	},
	pets: ['Tom', 'Jerry'],
	// or using this which uses current property of object
	//age: function(birthYear) {
		//return 2020 - birthYear;
	//}
	//calcAge: function() {
		//return 2020 - this.birthYear;
	//}
	calcAge: function() {
		this.age = 2020 - this.birthYear;
	}
}

console.log(john.family.sons[1]);
console.log(john['pets'][0]);
//console.log(john.calcAge(1999));
//john.age = john.calcAge(1999);
// or we can use this again to make property
john.calcAge();
console.log(john.age);
