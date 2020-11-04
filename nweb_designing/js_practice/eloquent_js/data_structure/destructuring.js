

function phi(table) {
	return (table[3] * table[0] - table[1] * table[2]) /
		Math.sqrt((table[2] + table[3]) *
		(table[0] + table[1]) *
		(table[1] + table[3]) *
		(table[0] + table[2]));
}

console.log(Math.round(phi([76, 9, 4, 1]) * 10000) / 10000);


/* destructuring */

// binding for the element of array
function phi([n00, n01, n10, n11]) {
	return (n11 * n00 - n10 * n01) /
		Math.sqrt((n10 + n11) * (n00 + n01) * (n01 + n11) *(n00 + n10));
}

console.log(Math.round(phi([76, 9, 4, 1]) * 10000) / 10000);

// A similar tricks works for objects, using braces instead of square brackets
let {name} = {name: "Faraji", age: 23};
console.log(name);
