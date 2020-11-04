/* of what I can get out of the exercise */

function reverseArray(array) {
	let i = array.length;
	let arr = [];
	while (i > 0) {
		arr.push(array[--i]);
	}
	return arr;
}

function reverseArrayInPlace(array) {
	let arr = [];
	for (let element of array) {
		let len = element.length;
		let newStr = "";
		while (len > 0) {
			// you can see that String in js can be treated as array
			newStr += element[--len];
		}
		arr.push(newStr);
	}
	return arr
}

console.log(reverseArray(["Hello", "How", "are", "you?"]));
console.log(reverseArrayInPlace(["Hello", "How", "are", "you?"]));
