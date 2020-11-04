// ... means, any number of paramter accepted

function maximum(...numbers) {
	let result = -Infinity;
	for (let number of numbers) {
		if (number > result) {
			result = number;
		}
	}
	return result;
}

function minimum(...numbers) {
	let result = Infinity;
	/* there's difference in "let number in numbers" and "let number of numbers", first one is typically range for the size of numbers, and second one is element accessing */
	for (let number of numbers) {
		if (number < result) {
			result = number;
		}
	}
	return result;
}

let words = ["nuver", "fully"];

console.log(maximum(4, 1, 9, -2));
console.log(minimum(4, 1, 9, -2));

/* unlike other languages(like java, C(didn't tried this in C)), you can have ...variable in any position, rather than of having last */
console.log(["will", ...words, "understand"]);
