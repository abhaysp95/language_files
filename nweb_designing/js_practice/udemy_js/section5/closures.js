function retirement(retirementAge) {
	let msg = " years left in retirement."
	return function(birthYear) {
		console.log((retirementAge - (2020 - birthYear)) + msg);
	}
}

let retirementUS = retirement(66);
retirementUS(1990);
retirement(66)(1982);


// Now as you can see, we are still able to use 'msg' and 'retirementAge' even though retirement is out of scope now, this is the closure, scope chain always remain intact

/* So, an inner function always have access to variables and parameters of outer functions even though outer functions have returned */


// generic function
/*function interviewQuestion(job) {
	if (job === "teacher") {
		return function(name) {
			return "Hello " + name + ", what do you teach?";
		}
	}
	else if (job == "designer") {
		return function(name) {
			return "Tell me " + name + ", what's your best design?";
		}
	}
	else {
		return function(name) {
			return "Hello " + name + ", what do you do?";
		}
	}
}*/

// rewriting interviewQuestion function for closure
function interviewQuestion(job) {
	return function(name) {
		if (job === "teacher") {
			return "Hello " + name + ", what do you teach?";
		}
		else if (job === "designer") {
			return "Tell me " + name + ", what's your best design?";
		}
		else {
			return "Hello " + name + ", what do you do?";
		}
	}
}

console.log(interviewQuestion("Teacher")("John"));
/* So the difference is that it returning the only function instead of 3
 * different functions(as done before) and is cleaner and can use "job" even
 * after interviewQuestion had been returned */
