// bmi challenge with object

var john = {
	fullName: 'John',
	lastName: 'Smith',
	mass: 72,
	height: 1.78,
	calcBmi: function() {
		this.bmi = Math.round(this.mass * 100.0 / (Math.pow(this.height, 2))) / 100;  // so it would return float
		return this.bmi
	}
}

var mark = {
	fullName: 'Mark',
	lastName: 'Stine',
	mass: 78,
	height: 1.78,
	calcBmi: function() {
		// all the extra calculation to get floating value upto 2 decimal point
		this.bmi = Math.round(this.mass * 100.0 / (Math.pow(this.height, 2))) / 100;
		return this.bmi;
	}
}

if (john.calcBmi() > mark.calcBmi()) {
	console.log("John has higher BMI than Mark");
}
else if (john.calcBmi() < mark.calcBmi()) {
	console.log("Mark has higher BMI than John");
}
else {
	console.log("Both John and Mark have same BMI");
}
