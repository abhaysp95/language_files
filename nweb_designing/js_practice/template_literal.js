var a = 10;
var b = 20;

function foo(strings, ...values) {
	let a = values[0]
	let b = values[1]
	console.log(values[2]);

	return `Sum ${a + b}
Product ${a * b}
Division ${b / a}`;
}

/* works also with => function */
const anotherFoo = (strings, ...values) => {
	strings.forEach((string) => {
		console.log(string + " - ");  // total number of string literal is more than values
	});
	let a = values[0]
	let b = values[1]
	console.log(values[2]);

	return `Sum ${a + b}
Product ${a * b}
Division ${b / a}`;
};

console.log(foo`Num1 ${a + b}
Num2 ${2 * b}
Num3 ${b / a}`);
console.log(anotherFoo`Num1 ${a + b}
Num2 ${2 * b}
Num3 ${b / a}`);
