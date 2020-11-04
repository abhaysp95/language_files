//the sum of the range

function range(start, end, step=1) {
	let array = [];
	while (start < end) {
		array.push(start);
		start += step;
	}
	return array;
}

function sum(array) {
	let sum = 0;
	for (let num of array) {
		sum += num;
	}
	return sum;
}

/*function tellArgs(a, b = 2, c = 4) {
	console.log(a + " " + b + " " + c);
}*/

console.log(range(1, 10));
console.log(range(1, 10, step=2));
console.log(range(1, 50, step=5));
console.log(sum(range(1, 10)));
console.log(sum(range(1, 50, step=5)));
/*console.log(tellArgs(10));
console.log(tellArgs(10, b = 20));
console.log(tellArgs(10, b = 20, c = 30));*/
